
package supernova

import chisel3._

object MemcpyISA {
  // funct values
  val CONFIG_SOURCE_CMD = 0.U
  val CONFIG_DEST_CMD = 1.U
  val MEMCPY_CMD = 2.U
  val MEMCPY_MULTI_CMD = 3.U
  val PROBE_CMD = 4.U
  val SET_CMD = 5.U

  val FLUSH_CMD = 7.U

  val GARBAGE_ADDR      = "hffffffff".U(32.W)

}

