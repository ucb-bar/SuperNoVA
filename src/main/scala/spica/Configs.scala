package spica

import chisel3._
import org.chipsalliance.cde.config.{Config, Parameters}
import freechips.rocketchip.diplomacy.LazyModule
import freechips.rocketchip.subsystem._
import freechips.rocketchip.tile.{BuildRoCC, OpcodeSet, XLen}
import freechips.rocketchip.rocket._
import freechips.rocketchip.tile._
import freechips.rocketchip.system._
import freechips.rocketchip.diplomacy._

import spica.Arithmetic.SIntArithmetic
import hardfloat._

// -----------------------
// Component Mixin Configs
// -----------------------

object MemcpyConfigs {
  val defaultConfig = MemcpyConfig(
    num_channel = 4,
    queue_length = 4,
    dma_buswidth = 128,
    dma_maxbyte = 64,
    tlb_size = 4,
    aligned_to = 1
  )

}

/**
 * Mixin which sets the default parameters for a systolic array accelerator.
   Also sets the system bus width to 128 bits (instead of the deafult 64 bits) to
   allow for the default 16x16 8-bit systolic array to be attached.
 */
class DefaultMemcpyConfig(
  memcpyConfig: MemcpyConfig = MemcpyConfigs.defaultConfig
) extends Config((site, here, up) => {
  case BuildRoCC => up(BuildRoCC) ++ Seq(
    (p: Parameters) => {
      implicit val q = p
      val memcpy = LazyModule(new Memcpy(memcpyConfig))
      memcpy
    }
  )
})
