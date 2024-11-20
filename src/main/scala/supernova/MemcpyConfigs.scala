
package supernova 

import scala.math.{max, pow, sqrt}
import chisel3._
import chisel3.util._
import freechips.rocketchip.tile._

case class MemcpyConfig(
                         opcodes: OpcodeSet = OpcodeSet.custom1,
                         num_channel: Int = 4,
                         queue_length: Int = 8, // command queue length
                         nXact: Int = 4, // number of memory request that can be tracked
                         dma_buswidth: Int = 128,
                         dma_maxbyte: Int = 64,
                         tlb_size: Int = 4,
                         aligned_to: Int = 1,
                         use_tlb_register_filter: Boolean = true,
                         use_dedicated_tl_port: Boolean = true,
                         use_shared_ext_mem: Boolean = false,
                         use_shared_tlb: Boolean = true,
                                                       ) {

}
