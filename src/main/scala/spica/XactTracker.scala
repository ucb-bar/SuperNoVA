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
  val mvout_addr = UInt(coreMaxAddrBits.W)
}

class XactTrackerAllocIO(nXacts: Int, maxShift: Int, maxReqBytes: Int)(implicit p: Parameters) extends Bundle {
  val valid = Output(Bool())
  val ready = Input(Bool())

  val xactid = Input(UInt(log2Up(nXacts).W))
  val entry = Output(new XactTrackerEntry(maxShift, maxReqBytes, nXacts))

  def fire(dummy: Int = 0) = valid && ready

}

class XactTrackerPeekIO[U <: Data](val nXacts: Int, val beatBits: Int, val maxReqBytes: Int)(implicit p: Parameters)
  extends Bundle {
  val xactid = Input(UInt(log2Up(nXacts).W))
  val pop = Input(Bool())
  val entry = Output(new XactTrackerEntry(beatBits, maxReqBytes, nXacts))
}

class XactTracker(nXacts: Int, beatBits: Int, maxReqBytes: Int)(implicit p: Parameters) extends Module {
  val io = IO(new Bundle {
    val alloc = Flipped(new XactTrackerAllocIO(nXacts, beatBits, maxReqBytes))
    val peek = new XactTrackerPeekIO(nXacts, beatBits, maxReqBytes)
    val busy = Output(Bool())
  })
  val maxShift = beatBits

  val entries = Reg(Vec(nXacts, UDValid(new XactTrackerEntry(maxShift, maxReqBytes, nXacts))))

  val free_entry = MuxCase((nXacts-1).U, entries.zipWithIndex.map { case (e, i) => !e.valid -> i.U })
  io.alloc.ready := !entries.map(_.valid).reduce(_ && _)
  io.alloc.xactid := free_entry

  io.peek.entry := entries(io.peek.xactid).bits

  io.busy := entries.map(_.valid).reduce(_ || _)

  when (io.alloc.fire()) {
    entries(free_entry).valid := true.B
    entries(free_entry).bits := io.alloc.entry
  }

  when (io.peek.pop) {
    entries(io.peek.xactid).valid := false.B
    assert(entries(io.peek.xactid).valid)
  }

  when (reset.asBool) {
    entries.foreach(_.valid := false.B)
  }


}
