
package spica

import java.nio.charset.StandardCharsets
import java.nio.file.{Files, Paths}

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tile._
import freechips.rocketchip.util.ClockGate
import freechips.rocketchip.tilelink.TLIdentityNode
import MemcpyISA._
import Util._
import freechips.rocketchip.rocket.MStatus

class ChannelConfig(val addr_bitwidth: Int, val state_bitwidth: Int) extends Bundle {
  val source_stride = UInt(addr_bitwidth.W)
  val dest_stride = UInt(addr_bitwidth.W)
  val source_base_addr = UInt(addr_bitwidth.W)
  val dest_base_addr = UInt(addr_bitwidth.W)
  val state = UInt(state_bitwidth.W)
  val source_direct_dram = Bool()
  val dest_direct_dram = Bool()

  val num_active_cmd = UInt(4.W) // ToDo: configurable
}

class MemcpyCmdBundle(data_bitwidth: Int, iterator_bitwidth: Int)(implicit p: Parameters) extends CoreBundle {
  val source_base_vaddr = UInt(coreMaxAddrBits.W)
  val dest_base_vaddr = UInt(coreMaxAddrBits.W)
  val source_stride = UInt(data_bitwidth.W)
  val dest_stride = UInt(data_bitwidth.W)
  val source_direct_dram = Bool()
  val dest_direct_dram = Bool()

  val status = new MStatus // ?
  val source_tile_offset = UInt(data_bitwidth.W)
  val dest_tile_offset = UInt(data_bitwidth.W)
  val tiles = UInt(iterator_bitwidth.W)
  val rows = UInt(iterator_bitwidth.W)
  val cols = UInt(data_bitwidth.W)
}

class MemcpyReqBundle(data_bitwidth: Int)(implicit p: Parameters) extends CoreBundle {
  val source_vaddr = UInt(coreMaxAddrBits.W)
  val dest_vaddr = UInt(coreMaxAddrBits.W)
  val source_direct_dram = Bool()
  val dest_direct_dram = Bool()
  val num_bytes = UInt(log2Up(data_bitwidth*4 + 1).W)

  val status = new MStatus // ?
}


class Memcpy(val config: MemcpyConfig)
                                     (implicit p: Parameters)
  extends LazyRoCC (
    opcodes = config.opcodes,
    nPTWPorts = if (config.use_shared_tlb) 1 else 2) {

  val xLen = p(XLen)
  val dma = LazyModule(new DMA(config))
  //val dma = LazyModule(new DMA(config, config.dma_buswidth, config.aligned_to, config.use_tlb_register_filter))

  override lazy val module = new MemcpyModule(this)
  override val tlNode = if (config.use_dedicated_tl_port) dma.id_node else TLIdentityNode()
  override val atlNode = if (config.use_dedicated_tl_port) TLIdentityNode() else dma.id_node

  val node = if (config.use_dedicated_tl_port) tlNode else atlNode
}

class MemcpyModule (outer: Memcpy)
    extends LazyRoCCModuleImp(outer)
    with HasCoreParameters {

  import outer.config._
  import outer.dma

  val tagWidth = 32


  // TLB
  implicit val edge = outer.dma.id_node.edges.out.head
  val tlb = Module(new FrontendTLB(2, tlb_size, dma_maxbyte, use_tlb_register_filter, false, use_shared_tlb))
  (tlb.io.clients zip outer.dma.module.io.tlb).foreach(t => t._1 <> t._2)

  tlb.io.exp.foreach(_.flush_skip := false.B)
  tlb.io.exp.foreach(_.flush_retry := false.B)

  io.ptw <> tlb.io.ptw

  outer.dma.module.io.flush := tlb.io.exp.map(_.flush()).reduce(_ || _)


  val state_bitwidth = 10
  val channel = Reg(Vec(num_channel, new ChannelConfig(coreMaxAddrBits, state_bitwidth))) // ToDo: state bitwidth as parameter

  //val raw_cmd_q = Queue(io.cmd, entries = queue_length)

  val iterator_bitwidth = 16
  val data_bitwidth = 32 // ToDo: parameterize
  val cmd = Reg(new MemcpyCmdBundle(data_bitwidth, iterator_bitwidth))

  val raw_cmd_q = Module(new Queue(new RoCCCommand, entries = queue_length))

  raw_cmd_q.io.enq.valid := false.B

  raw_cmd_q.io.deq.ready := true.B//added
  raw_cmd_q.io.enq.bits := io.cmd.bits//added

  io.cmd.ready := raw_cmd_q.io.enq.ready
  //val cmd_in = Queue(io.cmd)
  val cmd_in = Module(new Queue(new RoCCCommand, entries = 1))
  val is_config = cmd_in.io.deq.bits.inst.funct < 2.U
  val is_probe = cmd_in.io.deq.bits.inst.funct === PROBE_CMD || cmd_in.io.deq.bits.inst.funct === SET_CMD
  val is_flush = cmd_in.io.deq.bits.inst.funct === FLUSH_CMD

  // added io.resp initialization
  io.resp.valid := false.B
  io.resp.bits.data := 0.U
  io.resp.bits.rd := cmd_in.io.deq.bits.inst.rd

  io.cmd.ready := cmd_in.io.enq.ready
  cmd_in.io.enq.valid := io.cmd.valid
  cmd_in.io.enq.bits := io.cmd.bits
  cmd_in.io.deq.ready := true.B
  val cmd_in_deq = cmd_in.io.deq
  val tile_index = RegInit(0.U(state_bitwidth.W))
  when(cmd_in_deq.valid) {
    //val is_clock_gate_en = risc_funct === CLKGATE_EN
    when(is_flush) {
      val skip = cmd_in_deq.bits.rs1(0)
      cmd_in_deq.ready := true.B
      tlb.io.exp.foreach(_.flush_skip := skip)
      tlb.io.exp.foreach(_.flush_retry := !skip)
      channel.foreach(_.num_active_cmd := 0.U)
      channel.foreach(_.state := 0.U)
      //}
      //io.resp <> DontCare
    }.elsewhen(is_config) {
      val ch = cmd_in_deq.bits.rs1(4, 0)
      val stride = cmd_in_deq.bits.rs1 >> 5
      val base_addr = cmd_in_deq.bits.rs2(62,0)
      val direct_dram = cmd_in_deq.bits.rs2(63)
      cmd_in_deq.ready := true.B
      when(cmd_in_deq.fire) {
        when(channel(ch).num_active_cmd =/= 0.U){
          io.resp.valid := true.B
          io.resp.bits.data := false.B
          io.resp.bits.rd := cmd_in_deq.bits.inst.rd
        }
        .otherwise{
          io.resp.valid := true.B
          io.resp.bits.data := true.B
          io.resp.bits.rd := cmd_in_deq.bits.inst.rd
          when(cmd_in_deq.bits.inst.funct === CONFIG_SOURCE_CMD) {
            // configuring source
            channel(ch).source_base_addr := base_addr
            channel(ch).source_stride := stride
            channel(ch).state := 0.U // Do we need this?
            tile_index := 0.U
            channel(ch).source_direct_dram := direct_dram
          }.otherwise {
            // configuring dma
            channel(ch).dest_base_addr := base_addr
            channel(ch).dest_stride := stride
            channel(ch).state := 0.U // Do we need this?
            tile_index := 0.U
            channel(ch).dest_direct_dram := direct_dram
          }
        }
      }
      //io.resp <> DontCare
      // configuration command immediately commit for now
      // ToDo: how to make it safe? (if there are still operation going on)
    }.elsewhen(is_probe) {
      // immediately commit
      cmd_in_deq.ready := true.B
      val ch = cmd_in_deq.bits.rs1(4, 0) // ToDo: check
      when(cmd_in_deq.bits.inst.funct === PROBE_CMD) {
        io.resp.valid := true.B
        io.resp.bits.data := channel(ch).state
        io.resp.bits.rd := cmd_in_deq.bits.inst.rd
      }.otherwise {
        io.resp.valid := true.B
        when(channel(ch).num_active_cmd === 0.U){
          io.resp.bits.data := true.B
          //io.resp <> DontCare
          channel(ch).state := cmd_in_deq.bits.rs2
        }
        .otherwise{
          io.resp.bits.data := false.B
        }
      }
    }.elsewhen(!raw_cmd_q.io.enq.ready) { // ToDo replace with nuber of filled entries
      // queue full, can't receive any more command
      io.resp.valid := true.B
      io.resp.bits.data := 0.U // queue not available
      io.resp.bits.rd := cmd_in_deq.bits.inst.rd
      cmd_in_deq.ready := true.B
    }.otherwise {
      // can receive new memcpy command
      io.resp.valid := true.B
      io.resp.bits.data := 1.U
      io.resp.bits.rd := cmd_in_deq.bits.inst.rd
      cmd_in_deq.ready := false.B
      raw_cmd_q.io.enq.valid := true.B
      val ch = (cmd_in_deq.bits.rs1 >> 60).asUInt
      when(raw_cmd_q.io.enq.fire){
        channel(ch).num_active_cmd := channel(ch).num_active_cmd + 1.U
        cmd_in_deq.ready := true.B
      }
    }
  }
  raw_cmd_q.io.enq.bits := cmd_in_deq.bits
  dontTouch(io.resp)


  val (idle :: memcpying :: update :: Nil) = Enum(3)
  val state = RegInit(idle)


  val raw_cmd = raw_cmd_q.io.deq
  val req_issuer = Module(new LoopUnroller(outer.config, dma_buswidth, dma_maxbyte)) // lazymodule?
  val curr_channel = RegInit(0.U(log2Up(num_channel).W))
  val cmd_configured = RegInit(false.B)
  when(req_issuer.io.req.fire){
    cmd_configured := false.B
  }.elsewhen(raw_cmd.fire) {
    val is_multi = raw_cmd.bits.inst.funct === MEMCPY_MULTI_CMD
    val ch = (raw_cmd.bits.rs1 >> 60).asUInt
    curr_channel := ch
    cmd_configured := true.B
    state := memcpying
    when(is_multi) {
      cmd.tiles := raw_cmd.bits.rs2(63, 56)
      cmd.rows := raw_cmd.bits.rs1(53, 46)
      cmd.cols := raw_cmd.bits.rs1(45, 34)
      cmd.source_stride := channel(ch).source_stride
      cmd.dest_stride := channel(ch).dest_stride
      cmd.dest_base_vaddr := channel(ch).dest_base_addr + raw_cmd.bits.rs2(55, 32)
      cmd.source_base_vaddr := channel(ch).source_base_addr + raw_cmd.bits.rs2(31, 0)
      cmd.source_direct_dram := channel(ch).source_direct_dram
      cmd.dest_direct_dram := channel(ch).dest_direct_dram
      cmd.source_tile_offset := raw_cmd.bits.rs1(16, 0)
      cmd.dest_tile_offset := raw_cmd.bits.rs1(33, 17)
      tile_index := raw_cmd.bits.rs1(59, 54)
      cmd.status := raw_cmd.bits.status
    }.otherwise {
      cmd.tiles := 1.U
      cmd.source_tile_offset := 0.U
      cmd.dest_tile_offset := 0.U
      cmd.rows := raw_cmd.bits.rs1(51, 32)
      cmd.cols := raw_cmd.bits.rs2(31, 0)
      cmd.source_base_vaddr := channel(ch).source_base_addr + raw_cmd.bits.rs2(63, 32)
      cmd.dest_base_vaddr := channel(ch).dest_base_addr + raw_cmd.bits.rs1(31, 0)
      cmd.source_direct_dram := channel(ch).source_direct_dram
      cmd.dest_direct_dram := channel(ch).dest_direct_dram
      cmd.source_stride := channel(ch).source_stride
      cmd.dest_stride := channel(ch).dest_stride
      tile_index := raw_cmd.bits.rs1(59, 52)
      cmd.status := raw_cmd.bits.status
    }
  }.elsewhen(state === memcpying && !outer.dma.module.io.busy && !req_issuer.io.busy && !cmd_configured){
    state := update
  }
  when(state === update){
    channel(curr_channel).state := tile_index + 1.U // previous
    channel(curr_channel).num_active_cmd := channel(curr_channel).num_active_cmd - 1.U
    state := idle
  }

  raw_cmd.ready := state === idle //req_issuer.io.req.ready && !outer.dma.module.io.busy
  req_issuer.io.req.valid := cmd_configured //raw_cmd.valid
  req_issuer.io.req.bits := cmd
  req_issuer.io.out.ready := outer.dma.module.io.req.ready  // check
  //when(req_issuer.io.out.fire){
  //  channel(curr_channel).state := tile_index
  //}
  outer.dma.module.io.req.valid := req_issuer.io.out.valid
  outer.dma.module.io.req.bits := req_issuer.io.out.bits
  // vaddr, status, len


  // Wire up global RoCC signals
  //io.busy := raw_cmd.valid  || loop_matmul_unroller_busy || reservation_station.io.busy || dest.module.io.busy || unrolled_cmd.valid || loop_cmd.valid
  io.busy := raw_cmd.valid || dma.module.io.busy || req_issuer.io.busy || cmd_in_deq.valid

  io.interrupt := tlb.io.exp.map(_.interrupt).reduce(_ || _)

  assert(!io.interrupt, "Interrupt handlers have not been written yet")

}
