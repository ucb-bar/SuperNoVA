
package spica

import scala.math.{max, pow, sqrt}
import chisel3._
import chisel3.util._
import freechips.rocketchip.tile._

case class MemcpyConfig(
                         opcodes: OpcodeSet = OpcodeSet.custom1,
                         num_channel: Int = 4,
                         queue_length: Int = 8,
                         //max_in_flight_mem_reqs: Int = 8,
                         dma_buswidth: Int = 128,
                         dma_maxbyte: Int = 64,
                         tlb_size: Int = 4,
                         aligned_to: Int = 1,
                         use_tlb_register_filter: Boolean = true,
                         use_dedicated_tl_port: Boolean = true,
                         use_shared_ext_mem: Boolean = false,
                         use_shared_tlb: Boolean = true,
                         headerFileName: String = "dma_params.h"
                                                       ) {



}
