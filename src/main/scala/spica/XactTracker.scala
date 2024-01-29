package spica

import chisel3._
import chisel3.util._
import freechips.rocketchip.tile.CoreBundle
import spica.Util.UDValid
import midas.targetutils.SynthesizePrintf
import org.chipsalliance.cde.config.Parameters

class XactTrackerEntry(maxShift: Int, maxReqBytes: Int,
                       nCmds: Int)(implicit p: Parameters) extends CoreBundle {
  val shift = UInt(log2Up(maxShift).W)
  val bytes_to_read = UInt(log2Up(maxReqBytes+1).W)
  //val cmd_id = UInt(log2Up(nCmds).W)
  val mvout_direct_dram = Bool()
  val mvout_addr = UInt(coreMaxAddrBits.W)
}

class XactTrackerReadResponse(beatBits: Int, maxBytes: Int, max_blocks: Int)
                             (implicit p: Parameters) extends CoreBundle {
  //val data = UInt(log2Ceil(beatBits).W)
  //val dest_vaddr = UInt(coreMaxAddrBits.W)
  //val dest_direct_dram = Bool()
  val data = Vec(max_blocks, UInt((beatBits).W)) //UInt((maxBytes*8).W)
  //val len = UInt(8.W) // TODO magic number
  //val last = Bool()
  //val bytes_read = UInt(8.W) // TODO magic number
  // val cmd_id = UInt(8.W) // TODO magic number
  //val block = UInt(8.W)
  //val store_en = Bool()
  //val status = new MStatus
}

class XactTrackerAllocIO(nXacts: Int, maxShift: Int, maxReqBytes: Int, max_blocks: Int)(implicit p: Parameters) extends Bundle {
  val valid = Output(Bool())
  val ready = Input(Bool())

  val xactid = Input(UInt(log2Up(nXacts).W))
  val entry = Output(new XactTrackerEntry(maxShift, maxReqBytes, nXacts))
  //val value = Output(new XactTrackerReadResponse(maxShift, maxReqBytes))
  val value = Output(UInt((maxShift).W))

  val value_xactid = Output(UInt(log2Up(nXacts).W))
  val value_valid = Output(Bool())
  val blockid = Output(UInt(log2Up(max_blocks).W))
  val store_en = Output(Bool())
  //val value_ready = Input(Bool())

  def fire(dummy: Int = 0) = valid && ready
  //def result_fire(dummy: Int = 0) = value_valid && value_ready

}

class XactTrackerPeekIO[U <: Data](val nXacts: Int, val beatBits: Int, val maxReqBytes: Int)(implicit p: Parameters)
  extends Bundle {
  val xactid = Input(UInt(log2Up(nXacts).W))
  val pop = Input(Bool())  // delete entry when tl.d.fire
  val entry = Output(new XactTrackerEntry(beatBits, maxReqBytes, nXacts))
  //val value = Output(new XactTrackerReadResponse(beatBits, maxReqBytes))
  val value = Output(UInt((maxReqBytes*8).W))
  //val value_valid = Output(Bool()) // probing entry to
  val value_ready = Input(Bool())
}

class XactTrackerProbeIO[U <: Data](val nXacts: Int)(implicit p: Parameters)
  extends Bundle {
  val xactid = Output(UInt(log2Up(nXacts).W))
  val ready = Input(Bool())
  val valid = Output(Bool()) // whether there is available memory request
  def fire(dummy: Int = 0) = valid && ready
}

class XactTracker(nXacts: Int, beatBits: Int, maxReqBytes: Int, max_blocks: Int)(implicit p: Parameters) extends Module {
  val io = IO(new Bundle {
    val alloc = Flipped(new XactTrackerAllocIO(nXacts, beatBits, maxReqBytes, max_blocks))
    val peek = new XactTrackerPeekIO(nXacts, beatBits, maxReqBytes)
    val probe = new XactTrackerProbeIO(nXacts)
    val busy = Output(Bool())
    val is_free = Output(Bool())
  })
  val maxShift = beatBits

  val entries = Reg(Vec(nXacts, UDValid(new XactTrackerEntry(maxShift, maxReqBytes, nXacts))))
  val value_entries = Reg(Vec(nXacts, UDValid(new XactTrackerReadResponse(beatBits, maxReqBytes, max_blocks))))

  val free_entry = MuxCase((nXacts-1).U, entries.zipWithIndex.map { case (e, i) => !e.valid -> i.U })
  io.alloc.ready := !entries.map(_.valid).reduce(_ && _)
  io.alloc.xactid := free_entry

  io.peek.entry := entries(io.peek.xactid).bits
  io.peek.value := value_entries(io.peek.xactid).bits.data.asUInt
  val value_valid = value_entries(io.peek.xactid).valid
  when(value_valid && io.peek.value_ready){
    value_entries(io.peek.xactid).valid := false.B
    value_entries(io.peek.xactid).bits.data.foreach(_ := 0.U)
    assert(value_entries(io.peek.xactid).valid)
  }

  io.busy := entries.map(_.valid).reduce(_ || _)
  io.is_free := !entries.map(_.valid).reduce(_ && _)
  io.probe.valid := value_entries.map(_.valid).reduce(_ || _)

  io.probe.xactid := 0.U
  when(io.probe.fire()){
    for (i <- 0 to nXacts - 1){
      when(value_entries(i).valid){
        io.probe.xactid := i.U
      }
    }
  }

  when (io.alloc.fire()) {
    entries(free_entry).valid := true.B
    entries(free_entry).bits := io.alloc.entry
  }
  when(io.alloc.value_valid){
    value_entries(io.alloc.value_xactid).bits.data(io.alloc.blockid) := (io.alloc.value >> entries(io.alloc.value_xactid).bits.shift * 8.U).asUInt
    //value_entries(io.alloc.value_xactid).valid := true.B
    when(io.alloc.store_en){
      value_entries(io.alloc.value_xactid).valid := true.B
      //value_entries(io.alloc.value_xactid).bits.store_en := true.B
    }
  }

  when (io.peek.pop) {
    entries(io.peek.xactid).valid := false.B
    value_entries(io.peek.xactid).valid := false.B
    value_entries(io.peek.xactid).bits.data.foreach(_ := 0.U)
    assert(entries(io.peek.xactid).valid)
  }

  when (reset.asBool) {
    entries.foreach(_.valid := false.B)
    value_entries.foreach(_.valid := false.B)
    value_entries.foreach(_.bits.data.foreach(_ := 0.U))
  }


}
