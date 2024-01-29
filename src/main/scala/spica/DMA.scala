
package spica 

import chisel3._
import chisel3.util._
import chisel3.experimental.DataMirror

import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy.{IdRange, LazyModule, LazyModuleImp}
import freechips.rocketchip.tile.{CoreBundle, HasCoreParameters}
import freechips.rocketchip.tilelink._
import freechips.rocketchip.rocket.MStatus
import freechips.rocketchip.rocket.constants.MemoryOpConstants

import Util._

import midas.targetutils.PerfCounter
import midas.targetutils.SynthesizePrintf

class StreamReadRequest()(implicit p: Parameters) extends CoreBundle {
  val vaddr = UInt(coreMaxAddrBits.W)
  val direct_dram = Bool()
  val dest_direct_dram = Bool()
  val dest_vaddr = UInt(coreMaxAddrBits.W) // TODO use LocalAddr in DMA
  val status = new MStatus
  val len = UInt(8.W) // TODO magic number
  //val cmd_id = UInt(8.W) // TODO magic number

}

class StreamReadResponse(beatBits: Int, maxBytes: Int)
                                   (implicit p: Parameters) extends CoreBundle {
  //val data = UInt(log2Ceil(beatBits).W)
  val dest_vaddr = UInt(coreMaxAddrBits.W)
  val dest_direct_dram = Bool()
  //val data = UInt(beatBits.W)
  val data = UInt((8*maxBytes).W)
  val len = UInt(8.W) // TODO magic number
  //val last = Bool()
  //val bytes_read = UInt(8.W) // TODO magic number
  // val cmd_id = UInt(8.W) // TODO magic number
  //val block = UInt(8.W)

  //val store_en = Bool()
  //val status = new MStatus
}


class StreamWriteRequest(val dataWidth: Int, val maxBytes: Int)(implicit p: Parameters) extends CoreBundle {
  val vaddr = UInt(coreMaxAddrBits.W)
  val direct_dram = Bool()
  val data = UInt((8*maxBytes).W)
  val len = UInt(log2Up(maxBytes+1).W) // The number of bytes to write
  //val block = UInt(8.W) // TODO magic number
  val status = new MStatus

  //val store_en = Bool()
}

// TODO StreamReaderCore and StreamWriter are actually very alike. Is there some parent class they could both inherit from?
class StreamReader(nXacts: Int, beatBits: Int, maxBytes: Int, aligned_to: Int,
                   use_tlb_register_filter: Boolean)
                  (implicit p: Parameters) extends LazyModule {
  val node = TLClientNode(Seq(TLMasterPortParameters.v1(Seq(TLClientParameters(
    name = "memcpy-reader", sourceId = IdRange(0, nXacts))))))

  require(isPow2(aligned_to))

  // TODO when we request data from multiple rows which are actually contiguous in main memory, we should merge them into fewer requests

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) with HasCoreParameters with MemoryOpConstants {
    val (tl, edge) = node.out(0)

    val beatBytes = beatBits / 8
    val max_blocks = maxBytes / beatBytes

    val nCmds = 1 // (nXacts / meshRows) + 1

    val io = IO(new Bundle {
      val req = Flipped(Decoupled(new StreamReadRequest()))
      val resp = Decoupled(new StreamReadResponse(beatBits, maxBytes))
      val tlb = new FrontendTLBIO
      val flush = Input(Bool())
      val busy = Output(Bool())
    })
    val xacttracker = Module(new XactTracker(nXacts, beatBits, maxBytes, max_blocks))

    val (s_idle :: s_req_new_block :: Nil) = Enum(2)
    val state = RegInit(s_idle)

    val req = Reg(new StreamReadRequest())
    val vaddr = req.vaddr
    val direct_dram = req.direct_dram

    val bytesRequested = Reg(UInt(log2Ceil(maxBytes).W)) // TODO this only needs to count up to (dataBytes/aligned_to), right?
    val bytesLeft = req.len - bytesRequested // len is byte length
    //val bytesLeft = Mux(req.has_acc_bitwidth, req.len * (config.accType.getWidth / 8).U, req.len * (config.inputType.getWidth / 8).U) - bytesRequested

    val state_machine_ready_for_req = WireInit(state === s_idle)

    // Select the size and mask of the TileLink request
    class Packet extends Bundle {
      val size = UInt(log2Up(maxBytes+1).W)
      val lg_size = UInt(log2Ceil(log2Ceil(maxBytes+1)).W)
      val bytes_read = UInt(log2Up(maxBytes+1).W)
      val shift = UInt(log2Up(maxBytes).W)
      //val paddr = UInt(paddrBits.W)
      val vaddr = UInt(vaddrBits.W)
    }

    // ToDo: get rid of this as number of blocks is already calculated in unroller
    val read_sizes = ((aligned_to max beatBytes) to maxBytes by aligned_to).
      filter(s => isPow2(s)).
      filter(s => s % beatBytes == 0)
    val read_packets = read_sizes.map { s =>
      val lg_s = log2Ceil(s)
      val vaddr_aligned_to_size = if (s == 1) vaddr else Cat(vaddr(vaddrBits-1, lg_s), 0.U(lg_s.W))
      val vaddr_offset = if (s > 1) vaddr(lg_s-1, 0) else 0.U

      //dontTouch(vaddr_aligned_to_size)
      //dontTouch(vaddr_offset)

      val packet = Wire(new Packet())
      packet.size := s.U
      packet.lg_size := lg_s.U
      packet.bytes_read := minOf(s.U - vaddr_offset, bytesLeft)
      packet.shift := vaddr_offset
      packet.vaddr := vaddr_aligned_to_size
      dontTouch(packet)

      packet
    }
    val read_packet = read_packets.reduce { (acc, p) =>
      Mux(p.bytes_read > acc.bytes_read, p, acc)
    }
    val read_vaddr = read_packet.vaddr
    val read_lg_size = read_packet.lg_size
    val read_bytes_read = read_packet.bytes_read
    val read_shift = read_packet.shift

    val reserve = xacttracker.io.alloc
    // Firing off TileLink read requests and allocating space inside the reservation buffer for them
    val get = edge.Get(
      fromSource = reserve.xactid,
      toAddress = 0.U, //read_paddr,
      lgSize = read_lg_size
    )._2

    class TLBundleAWithInfo extends Bundle {
      val tl_a = DataMirror.internal.chiselTypeClone[TLBundleA](tl.a.bits)
      val vaddr = Output(UInt(vaddrBits.W))
      val status = Output(new MStatus)
    }

    val untranslated_a = Wire(Decoupled(new TLBundleAWithInfo))
    val tlb_q = Module(new Queue(new TLBundleAWithInfo, 1, pipe=true))
    untranslated_a.valid := state === s_req_new_block && reserve.ready
    //untranslated_a.valid := state === s_req_new_block && io.resp.ready
    //untranslated_a.valid := state === s_req_new_block && io.resp.ready && !tlb_q.io.deq.valid // added tlb_q to avoid translate_q deq malfunctioning -> why?
    untranslated_a.bits.tl_a := get
    untranslated_a.bits.vaddr := read_vaddr
    untranslated_a.bits.status := req.status

    //reserve.ready := state === s_req_new_block && untranslated_a.ready
    reserve.valid := state === s_req_new_block && untranslated_a.fire
    reserve.entry.shift := RegEnableThru(read_shift, untranslated_a.fire)
    reserve.entry.bytes_to_read := RegEnableThru(read_bytes_read, untranslated_a.fire)
    reserve.entry.mvout_addr := RegEnableThru(req.dest_vaddr, untranslated_a.fire)
    reserve.entry.mvout_direct_dram := RegEnableThru(req.dest_direct_dram, untranslated_a.fire)
    /*
    when(untranslated_a.fire){
      reserve.entry.shift := read_shift
      reserve.entry.bytes_to_read := read_bytes_read
      reserve.entry.mvout_addr := req.dest_vaddr
    }
     */

    // 0 goes to retries, 1 goes to state machine
    val retry_a = Wire(Decoupled(new TLBundleAWithInfo))
    val tlb_arb = Module(new Arbiter(new TLBundleAWithInfo, 2))
    tlb_arb.io.in(0) <> retry_a
    tlb_arb.io.in(1) <> untranslated_a

    //val tlb_q = Module(new Queue(new TLBundleAWithInfo, 1, pipe=true))
    tlb_q.io.enq <> tlb_arb.io.out

    io.tlb.req.valid := tlb_q.io.deq.valid
    io.tlb.req.bits := DontCare
    io.tlb.req.bits.tlb_req.vaddr := tlb_q.io.deq.bits.vaddr
    io.tlb.req.bits.tlb_req.passthrough := false.B
    io.tlb.req.bits.tlb_req.size := 0.U // send_size
    io.tlb.req.bits.tlb_req.cmd := M_XRD
    io.tlb.req.bits.status := tlb_q.io.deq.bits.status
    // fix for interrupt assertion
    io.tlb.req.bits.tlb_req.v := tlb_q.io.deq.bits.status.v
    io.tlb.req.bits.tlb_req.prv := tlb_q.io.deq.bits.status.prv

    val translate_q = Module(new Queue(new TLBundleAWithInfo, 1, pipe=true))
    translate_q.io.enq <> tlb_q.io.deq
    translate_q.io.deq.ready := true.B
    dontTouch(translate_q.io.deq.ready)
    dontTouch(translate_q.io.deq.valid)
    dontTouch(translate_q.io.enq.ready)
    dontTouch(translate_q.io.enq.valid)
    val translate_q_fire = WireInit(translate_q.io.deq.fire)
    dontTouch(translate_q_fire)

    retry_a.valid := translate_q.io.deq.valid && (io.tlb.resp.miss || !tl.a.ready)
    retry_a.bits := translate_q.io.deq.bits
    assert(retry_a.ready)

    tl.a.valid := translate_q.io.deq.valid && !io.tlb.resp.miss
    tl.a.bits := translate_q.io.deq.bits.tl_a
    tl.a.bits.address := Mux(direct_dram, (1.U << (4+32)).asUInt + io.tlb.resp.paddr, io.tlb.resp.paddr)

    //val bytes_per_packet = Reg(Vec(max_blocks, UInt(log2Up(beatBytes+1).W)))
    //val bytes_total_packet = RegInit(0.U(log2Up(maxBytes+1).W))

    val packet_index = RegInit(0.U(log2Up(max_blocks+1).W))
    when (untranslated_a.fire) {
      val next_vaddr = req.vaddr + read_bytes_read // send_size
      val new_page = next_vaddr(pgIdxBits-1, 0) === 0.U
      req.vaddr := next_vaddr
      //bytes_total_packet := read_bytes_read
      //packet_index := packet_index + 1.U

      bytesRequested := bytesRequested + read_bytes_read // send_size

      // when (send_size >= bytesLeft) {
      when (read_bytes_read >= bytesLeft) {
        // We're done with this request at this point
        //state_machine_ready_for_req := true.B
        state := s_idle //s_resp_block
        //packet_index := 0.U
      }
    }

    io.busy := (state =/= s_idle) | xacttracker.io.busy
    io.req.ready := state === s_idle && xacttracker.io.is_free // only when there is an available entry

    val (r_idle :: r_sending_request :: Nil) = Enum(2)
    val r_state = RegInit(r_idle)

    // Forward TileLink read responses to the reservation buffer
    // tl.d.ready := io.beatData.ready
    io.resp.valid := false.B
    // reset
    io.resp.bits.data := 0.U
    io.resp.bits.len := 0.U
    //io.resp.bits.block := 0.U
    //io.resp.bits.store_en := false.B
    io.resp.bits.dest_vaddr := 0.U
    io.resp.bits.dest_direct_dram := false.B


    val last_resp_packet = WireInit(edge.last(tl.d))
    val tl_d_fire = WireInit(tl.d.fire)
    dontTouch(tl_d_fire)
    dontTouch(last_resp_packet)
    dontTouch(io.resp.ready)
    when (state === s_idle){
      //bytes_per_packet := VecInit(Seq.fill(max_blocks)(0.U))
      //bytes_total_packet := 0.U
      //packet_index := 0.U
      //io.req.ready := true.B
      when (io.req.fire){
        req := io.req.bits
        bytesRequested := 0.U
        state := s_req_new_block
        io.busy := true.B
      }
    }
    // response
    tl.d.ready := true.B // io.resp.ready

    reserve.value_valid := tl.d.valid
    reserve.value_xactid := tl.d.bits.source
    reserve.value := (tl.d.bits.data) // >> (xacttracker.io.peek.entry.shift * 8.U)).asUInt
    reserve.store_en := last_resp_packet && tl_d_fire
    reserve.blockid := packet_index

    when(tl_d_fire){
      //io.resp.valid := tl.d.valid
      //io.resp.bits.data := (tl.d.bits.data >> (xacttracker.io.peek.entry.shift * 8.U)).asUInt // shift in bits //tl.d.bits.data
      //io.resp.bits.len := Mux(bytes_total_packet > beatBytes.asUInt, beatBytes.asUInt, bytes_total_packet - beatBytes.asUInt)  //bytes_per_packet(packet_index)
      //io.resp.bits.block := packet_index
      //resp_data := resp_data + (tl.d.bits.data << loaded_bits).asUInt
      //loaded_bits := loaded_bits + (bytes_per_packet(packet_index) << 3.U).asUInt
      packet_index := packet_index + 1.U
      when(last_resp_packet) {
        //state := s_idle
        //io.resp.bits.store_en := true.B
        packet_index := 0.U
      }
    }

    val probe_xactid = RegInit(0.U(log2Up(nXacts).W))
    xacttracker.io.peek.xactid := probe_xactid
    //xacttracker.io.peek.pop := last_resp_packet && tl_d_fire
    xacttracker.io.peek.pop := io.resp.fire
    io.resp.bits.dest_vaddr := xacttracker.io.peek.entry.mvout_addr
    io.resp.bits.dest_direct_dram := xacttracker.io.peek.entry.mvout_direct_dram
    // ToDo: when it is not aligned to 16 bytes
    io.resp.bits.len := xacttracker.io.peek.entry.bytes_to_read
    io.resp.bits.data := xacttracker.io.peek.value
    io.resp.valid := r_state === r_sending_request
    xacttracker.io.peek.value_ready := false.B
    xacttracker.io.probe.ready := r_state === r_idle
    when(r_state === r_idle) {
      when(xacttracker.io.probe.valid) {
        probe_xactid := xacttracker.io.probe.xactid
        r_state := r_sending_request
      }
    }.elsewhen(r_state === r_sending_request){
      xacttracker.io.peek.value_ready := io.resp.ready
      io.resp.valid := true.B
      when(io.resp.fire){
        r_state := r_idle
      }
    }
  }
}

// beatBits: dma_busbitwidth
class StreamWriter(nXacts: Int, beatBits: Int, maxBytes: Int, aligned_to: Int, use_tlb_register_filter: Boolean)
                                         (implicit p: Parameters) extends LazyModule {
  val node = TLClientNode(Seq(TLMasterPortParameters.v1(Seq(TLClientParameters(
    name = "memcpy-writer", sourceId = IdRange(0, nXacts))))))

  require(isPow2(aligned_to))

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) with HasCoreParameters with MemoryOpConstants {
    val (tl, edge) = node.out(0)
    val beatBytes = beatBits / 8
    val dataBytes = beatBytes //dataWidth / 8
    val lgBeatBytes = log2Ceil(beatBytes)
    val maxBeatsPerReq = maxBytes / beatBytes
    //val inputTypeRowBytes = block_cols * inputType.getWidth / 8
    val maxBlocks = maxBeatsPerReq //maxBytes / inputTypeRowBytes

    require(beatBytes > 0)

    val io = IO(new Bundle {
      val req = Flipped(Decoupled(new StreamWriteRequest(beatBits, maxBytes)))
      val tlb = new FrontendTLBIO
      val busy = Output(Bool())
      val flush = Input(Bool())
    })

    val (s_idle :: s_writing_new_block :: s_writing_beats :: Nil) = Enum(3)
    val state = RegInit(s_idle)

    val req = Reg(new StreamWriteRequest(beatBits, maxBytes))

    // TODO use the same register to hold data_blocks and data_single_block, so that this Mux here is not necessary
    //val data_blocks = Reg(Vec(maxBlocks, UInt(beatBits.W)))
    //val data_single_block = Reg(UInt(beatBits.W)) // For data that's just one-block-wide
    //val data = Mux(req.block === 0.U, data_single_block, data_blocks.asUInt)

    val bytesSent = Reg(UInt(log2Ceil((dataBytes max maxBytes)+1).W))  // TODO this only needs to count up to (dataBytes/aligned_to), right?
    val bytesLeft = req.len - bytesSent


    val xactBusy = RegInit(0.U(nXacts.W))
    val xactOnehot = PriorityEncoderOH(~xactBusy)
    val xactId = OHToUInt(xactOnehot)

    val xactBusy_fire = WireInit(false.B)
    val xactBusy_add = Mux(xactBusy_fire, (1.U << xactId).asUInt, 0.U)
    val xactBusy_remove = ~Mux(tl.d.fire, (1.U << tl.d.bits.source).asUInt, 0.U)
    xactBusy := (xactBusy | xactBusy_add) & xactBusy_remove.asUInt
    dontTouch(xactBusy_add)
    dontTouch(xactBusy_remove)

    val state_machine_ready_for_req = WireInit(state === s_idle)
    io.req.ready := state_machine_ready_for_req
    io.busy := xactBusy.orR || (state =/= s_idle)

    val vaddr = req.vaddr
    val direct_dram = req.direct_dram
    val data = req.data

    // Select the size and mask of the TileLink request
    class Packet extends Bundle {
      val size = UInt(log2Ceil(maxBytes+1).W)
      val lg_size = UInt(log2Ceil(log2Ceil(maxBytes+1)+1).W)
      val mask = Vec(maxBeatsPerReq, Vec(beatBytes, Bool()))
      val vaddr = UInt(vaddrBits.W)
      val is_full = Bool()

      val bytes_written = UInt(log2Up(maxBytes+1).W)
      val bytes_written_per_beat = Vec(maxBeatsPerReq, UInt(log2Up(beatBytes+1).W))

      def total_beats(dummy: Int = 0) = Mux(size < beatBytes.U, 1.U, size / beatBytes.U(size.getWidth.W)) // The width expansion is added here solely to satsify Verilator's linter
    }

    val smallest_write_size = aligned_to max beatBytes
    val write_sizes = (smallest_write_size to maxBytes by aligned_to).
      filter(s => isPow2(s)).
      filter(s => s % beatBytes == 0) /*.
      filter(s => s <= dataBytes*2 || s == smallest_write_size)*/
    val write_packets = write_sizes.map { s =>
      val lg_s = log2Ceil(s)
      val vaddr_aligned_to_size = if (s == 1) vaddr else Cat(vaddr(vaddrBits-1, lg_s), 0.U(lg_s.W))
      val vaddr_offset = if (s > 1) vaddr(lg_s - 1, 0) else 0.U

      val mask = (0 until maxBytes).map { i => i.U >= vaddr_offset && i.U < vaddr_offset +& bytesLeft && (i < s).B }

      val bytes_written = {
        Mux(vaddr_offset +& bytesLeft > s.U, s.U - vaddr_offset, bytesLeft)
      }

      val packet = Wire(new Packet())
      packet.size := s.U
      packet.lg_size := lg_s.U
      packet.mask := VecInit(mask.grouped(beatBytes).map(v => VecInit(v)).toSeq)
      packet.vaddr := vaddr_aligned_to_size
      packet.is_full := mask.take(s).reduce(_ && _)

      packet.bytes_written := bytes_written
      packet.bytes_written_per_beat.zipWithIndex.foreach { case (b, i) =>
        val start_of_beat = i * beatBytes
        val end_of_beat = (i+1) * beatBytes

        val left_shift = Mux(vaddr_offset >= start_of_beat.U && vaddr_offset < end_of_beat.U,
          vaddr_offset - start_of_beat.U,
          0.U)

        val right_shift = Mux(vaddr_offset +& bytesLeft >= start_of_beat.U && vaddr_offset +& bytesLeft < end_of_beat.U,
          end_of_beat.U - (vaddr_offset +& bytesLeft),
          0.U)

        val too_early = vaddr_offset >= end_of_beat.U
        val too_late = vaddr_offset +& bytesLeft <= start_of_beat.U

        b := Mux(too_early || too_late, 0.U, beatBytes.U - (left_shift +& right_shift))
      }

      packet
    }
    val best_write_packet = write_packets.reduce { (acc, p) =>
      Mux(p.bytes_written > acc.bytes_written, p, acc)
    }
    val write_packet = RegEnableThru(best_write_packet, state === s_writing_new_block)

    val write_size = write_packet.size
    val lg_write_size = write_packet.lg_size
    val write_beats = write_packet.total_beats()
    val write_vaddr = write_packet.vaddr
    val write_full = write_packet.is_full

    val beatsLeft = Reg(UInt(log2Up(maxBytes/aligned_to).W))
    val beatsSent = Mux(state === s_writing_new_block, 0.U, write_beats - beatsLeft)

    val write_mask = write_packet.mask(beatsSent)
    val write_shift = PriorityEncoder(write_mask)

    val bytes_written_this_beat = write_packet.bytes_written_per_beat(beatsSent)
    val untranslate_fired = RegInit(false.B) // to avoid duplicated firing for multi-blocked mvout

    // Firing off TileLink write requests
    val putFull = edge.Put(
      fromSource = RegEnableThru(xactId, state === s_writing_new_block && !untranslate_fired),
      toAddress = 0.U,
      lgSize = lg_write_size,
      data = (data >> (bytesSent * 8.U)).asUInt
    )._2

    val putPartial = edge.Put(
      fromSource = RegEnableThru(xactId, state === s_writing_new_block && !untranslate_fired),
      toAddress = 0.U,
      lgSize = lg_write_size,
      data = ((data >> (bytesSent * 8.U)) << (write_shift * 8.U)).asUInt,
      mask = write_mask.asUInt
    )._2

    class TLBundleAWithInfo extends Bundle {
      val tl_a = DataMirror.internal.chiselTypeClone[TLBundleA](tl.a.bits)
      val vaddr = Output(UInt(vaddrBits.W))
      val status = Output(new MStatus)
    }

    val untranslated_a = Wire(Decoupled(new TLBundleAWithInfo))
    xactBusy_fire := untranslated_a.fire && state === s_writing_new_block
    untranslated_a.valid := (state === s_writing_new_block) && !xactBusy.andR && !untranslate_fired
    //untranslated_a.valid := (state === s_writing_new_block || state === s_writing_beats) && !xactBusy.andR
    untranslated_a.bits.tl_a := Mux(write_full, putFull, putPartial)
    untranslated_a.bits.vaddr := write_vaddr
    untranslated_a.bits.status := req.status

    // 0 goes to retries, 1 goes to state machine
    val retry_a = Wire(Decoupled(new TLBundleAWithInfo))
    val shadow_retry_a = Module(new Queue(new TLBundleAWithInfo, 1))
    shadow_retry_a.io.enq.valid := false.B
    shadow_retry_a.io.enq.bits := DontCare
    val tlb_arb = Module(new Arbiter(new TLBundleAWithInfo, 3))
    tlb_arb.io.in(0) <> retry_a
    tlb_arb.io.in(1) <> shadow_retry_a.io.deq
    tlb_arb.io.in(2) <> untranslated_a

    val tlb_q = Module(new Queue(new TLBundleAWithInfo, 1, pipe=true))
    tlb_q.io.enq <> tlb_arb.io.out

    io.tlb.req.bits := DontCare
    io.tlb.req.valid := tlb_q.io.deq.fire
    io.tlb.req.bits.tlb_req.vaddr := tlb_q.io.deq.bits.vaddr
    io.tlb.req.bits.tlb_req.passthrough := false.B
    io.tlb.req.bits.tlb_req.size := 0.U // send_size
    io.tlb.req.bits.tlb_req.cmd := M_XWR
    io.tlb.req.bits.status := tlb_q.io.deq.bits.status
    // fix for interrupt assertion
    io.tlb.req.bits.tlb_req.v := tlb_q.io.deq.bits.status.v
    io.tlb.req.bits.tlb_req.prv := tlb_q.io.deq.bits.status.prv

    val translate_q = Module(new Queue(new TLBundleAWithInfo, 1, pipe=true))
    translate_q.io.enq <> tlb_q.io.deq
    when (retry_a.valid) {
      translate_q.io.enq.valid := false.B
      shadow_retry_a.io.enq.valid := tlb_q.io.deq.valid
      shadow_retry_a.io.enq.bits  := tlb_q.io.deq.bits
    }
    translate_q.io.deq.ready := tl.a.ready || io.tlb.resp.miss

    retry_a.valid := translate_q.io.deq.valid && io.tlb.resp.miss
    retry_a.bits := translate_q.io.deq.bits
    assert(!(retry_a.valid && !retry_a.ready))


    tl.a.valid := Mux(state === s_writing_beats, true.B, translate_q.io.deq.valid && !io.tlb.resp.miss && state === s_writing_new_block)
    tl.a.bits := Mux(state === s_writing_beats, Mux(write_full, putFull, putPartial), translate_q.io.deq.bits.tl_a)
    val address = Mux(direct_dram, (1.U << (4+32)).asUInt + io.tlb.resp.paddr, io.tlb.resp.paddr)
    tl.a.bits.address := RegEnableThru(address, RegNext(io.tlb.req.fire))

    tl.d.ready := xactBusy.orR

    when(untranslated_a.fire){
      //state := s_writing_beats
      beatsLeft := write_beats
      untranslate_fired := true.B
    }
    when(state === s_writing_new_block && tl.a.fire){
      state := s_writing_beats
    }
    when(tl.a.fire){
      when(beatsLeft === 1.U){
        state := s_idle
        state_machine_ready_for_req := true.B
        untranslate_fired := false.B
      }
      val next_vaddr = req.vaddr + write_packet.bytes_written
      req.vaddr := next_vaddr
      bytesSent := bytesSent + bytes_written_this_beat
      beatsLeft := beatsLeft - 1.U
    }

    // Accepting requests to kick-start the state machine
    when (io.req.fire) {

      req := io.req.bits
      //req.len := io.req.bits.block * beatBytes.U + io.req.bits.len

      //data_single_block := io.req.bits.data
      //data_blocks(io.req.bits.block) := io.req.bits.data

      bytesSent := 0.U

      state := s_writing_new_block //s_idle
      //state := Mux(io.req.bits.store_en, s_writing_new_block, s_idle)

    }

  }
}

// connects reader and writer
class DMA(config: MemcpyConfig)
         (implicit p: Parameters) extends LazyModule {

  import config._

  val maxBytes = dma_maxbyte
  val dataBits = dma_buswidth


  val id_node = TLIdentityNode()
  val xbar_node = TLXbar()

  val reader = LazyModule(new StreamReader(nXact, dataBits, maxBytes, aligned_to, use_tlb_register_filter))
  val writer = LazyModule(new StreamWriter(nXact, dataBits, maxBytes, aligned_to, use_tlb_register_filter)) // parameterize

  // TODO make a cross-bar vs two separate ports a config option
  // id_node :=* reader.node
  // id_node :=* writer.node

  xbar_node := TLBuffer() := reader.node // TODO
  xbar_node := TLBuffer() := writer.node
  id_node := TLWidthWidget(config.dma_buswidth/8) := TLBuffer() := xbar_node

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) with HasCoreParameters {
    val io = IO(new Bundle {
      val req = Flipped(Decoupled(new MemcpyReqBundle(dma_buswidth)))
      // TLB ports
      val tlb = Vec(2, new FrontendTLBIO)

      // Misc. ports
      val busy = Output(Bool())
      val flush = Input(Bool())
      //val counter = new CounterEventIO()
    })
    val (idle :: memcpying :: Nil) = Enum(2)
    val state = RegInit(idle)
    val dma_busy = writer.module.io.busy || reader.module.io.busy || writer.module.io.req.fire || reader.module.io.req.fire

    val req = Reg(new MemcpyReqBundle(dma_buswidth))
    io.busy := dma_busy || io.req.fire //state =/= idle
    //io.req.ready := state === idle
    io.req.ready := reader.module.io.req.ready
    reader.module.io.req.valid := false.B
    reader.module.io.req.bits.vaddr := Mux(io.req.fire, io.req.bits.source_vaddr, req.source_vaddr)
    reader.module.io.req.bits.status := Mux(io.req.fire, io.req.bits.status, req.status)
    reader.module.io.req.bits.len := Mux(io.req.fire, io.req.bits.num_bytes, req.num_bytes)
    reader.module.io.req.bits.dest_vaddr := Mux(io.req.fire, io.req.bits.dest_vaddr, req.dest_vaddr) // fed dest vaddr to track
    reader.module.io.req.bits.direct_dram := Mux(io.req.fire, io.req.bits.source_direct_dram, req.source_direct_dram)
    reader.module.io.req.bits.dest_direct_dram := Mux(io.req.fire, io.req.bits.dest_direct_dram, req.dest_direct_dram)
    when(state === idle) {
      // to eliminate pipeline bubbles
      when(io.req.fire) { // it implies reader.module.io.req.ready true already
        reader.module.io.req.valid := true.B
        req := io.req.bits
        state := memcpying
        //io.busy := true.B
      }
    }
    .elsewhen(state === memcpying && io.req.ready){
      state := idle
      // to eliminate pipeline bubbles
      when(io.req.fire){ // it implies reader.module.io.req.ready true already
        reader.module.io.req.valid := true.B
        state := memcpying
        req := io.req.bits
      }
    }

    val dma_pipe_delay = 1 // ToDo
    //val write_issue_q = Queue(reader.module.io.resp)
    val write_issue_q = Module(new Queue(new StreamReadResponse(dataBits, maxBytes), 2))

    write_issue_q.io.deq.ready := writer.module.io.req.ready
    reader.module.io.resp.ready := write_issue_q.io.enq.ready
    write_issue_q.io.enq.valid := reader.module.io.resp.valid
    write_issue_q.io.enq.bits := reader.module.io.resp.bits

    writer.module.io.req.valid := write_issue_q.io.deq.valid
    writer.module.io.req.bits.data := write_issue_q.io.deq.bits.data
    writer.module.io.req.bits.status := req.status
    writer.module.io.req.bits.vaddr := write_issue_q.io.deq.bits.dest_vaddr // fed from reader
    writer.module.io.req.bits.len := write_issue_q.io.deq.bits.len //req.num_bytes
    //writer.module.io.req.bits.block := write_issue_q.io.deq.bits.block
    //writer.module.io.req.bits.store_en := write_issue_q.io.deq.bits.store_en
    writer.module.io.req.bits.direct_dram := write_issue_q.io.deq.bits.dest_direct_dram

    io.tlb(0) <> writer.module.io.tlb
    io.tlb(1) <> reader.module.io.tlb

    writer.module.io.flush := io.flush
    reader.module.io.flush := io.flush

    //io.busy := writer.module.io.busy || reader.module.io.busy || writer.module.io.req.fire || reader.module.io.req.fire

  }
}
