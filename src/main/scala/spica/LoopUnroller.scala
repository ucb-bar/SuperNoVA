package spica

import chisel3._
import chisel3.util._
import chisel3.experimental._
import freechips.rocketchip.tile.{CoreBundle, RoCCCommand}
import org.chipsalliance.cde.config.Parameters
import MemcpyISA._
import Util._
import freechips.rocketchip.diplomacy.LazyModule
import freechips.rocketchip.rocket.MStatus


class LoopUnroller(config: MemcpyConfig, dma_bitwidth: Int, dma_maxbyte: Int)(implicit p: Parameters) extends Module {
  val iterator_bitwidth = 16
  val data_bitwidth = 32
  val GARBAGE_ADDR = ~0.U(32.W)

  val io = IO(new Bundle {
    val req = Flipped(Decoupled(new MemcpyCmdBundle(data_bitwidth, iterator_bitwidth)))
    val out = Decoupled(new MemcpyReqBundle(data_bitwidth))
    //val done = Output(Bool())
    val busy = Output(Bool())
  })

  object State extends ChiselEnum {
    val idle, memcpy = Value
  }
  import State._

  val state = RegInit(idle)
  val req = Reg(new MemcpyCmdBundle(data_bitwidth, iterator_bitwidth))

  val max_bytes = dma_maxbyte.asUInt // how many bytes per row per operation
  val max_bytes_bit = log2Up(dma_maxbyte) // 6 for 64 bytes
  val beat_bytes = dma_bitwidth / 8
  val beat_bytes_bit = log2Up(beat_bytes)

  val tile = RegInit(0.U(iterator_bitwidth.W))
  val row = RegInit(0.U(iterator_bitwidth.W))
  val col = RegInit(0.U(iterator_bitwidth.W)) // in bytes

  val max_tiles = req.tiles
  val max_rows = req.rows
  val max_cols = req.cols

  // TODO get rid of the x * max_y multiplications here
  val source_vaddr = req.source_base_vaddr + req.source_tile_offset * tile + req.source_stride * row + col
  val dest_vaddr = req.dest_base_vaddr + req.dest_tile_offset * tile + req.dest_stride * row + col
  // for address alignment
  // SW needs to avoid this
  val eff_beat_bytes = WireInit(Mux((beat_bytes.asUInt - source_vaddr(beat_bytes_bit-1, 0)) > (beat_bytes.asUInt - dest_vaddr(beat_bytes_bit - 1, 0)),
    beat_bytes.asUInt - dest_vaddr(beat_bytes_bit - 1, 0), beat_bytes.asUInt - source_vaddr(beat_bytes_bit-1, 0)))
  val col_bytes = WireInit(Mux(col + eff_beat_bytes > max_cols, max_cols - col, eff_beat_bytes))
  val source_vaddr_offset = source_vaddr(max_bytes_bit-1, 0)
  val dest_vaddr_offset = dest_vaddr(max_bytes_bit-1, 0)

  val source_align_next = source_vaddr - source_vaddr_offset + (1 << max_bytes_bit).asUInt
  val dest_align_next = dest_vaddr - dest_vaddr_offset + (1 << max_bytes_bit).asUInt
  val source_align_offset = source_align_next - source_vaddr
  val dest_align_offset = dest_align_next - dest_vaddr
  val min_align_offset = Mux(source_align_offset < dest_align_offset, source_align_offset, dest_align_offset)
  dontTouch(source_align_offset)
  dontTouch(dest_align_offset)
  dontTouch(dest_vaddr_offset)

  // ToDo: better parameterize
  if(dma_maxbyte > beat_bytes) {
    // force 2nd, 4th beat position size to beatsize
    when(source_vaddr_offset(beat_bytes_bit, 0) === 0.U && dest_vaddr_offset(beat_bytes_bit, 0) === 0.U) {
    //when(source_vaddr_offset(beat_bytes_bit) =/= 1.U && dest_vaddr_offset(beat_bytes_bit) =/= 1.U) {
      val col_bytes_temp = Mux(col + min_align_offset > max_cols, max_cols - col, min_align_offset)
      col_bytes := Mux(col_bytes_temp > 32.U && col_bytes_temp <= 48.U, 32.U, col_bytes_temp) // no 3 beats
      //val col_bytes = Mux(col + max_bytes > max_cols, max_cols - col, max_bytes)
    }
  }
  dontTouch(col_bytes)

  val last_iteration = tile === max_tiles - 1.U && col === max_cols - col_bytes && row === max_rows - 1.U


  io.req.ready := false.B
  io.out.valid := false.B
  io.out.bits.source_vaddr := source_vaddr
  io.out.bits.dest_vaddr := dest_vaddr
  io.out.bits.source_direct_dram := req.source_direct_dram
  io.out.bits.dest_direct_dram := req.dest_direct_dram
  io.out.bits.num_bytes := col_bytes
  io.out.bits.status := req.status

  /*
  def increment(): Unit = {
    val next_r = floorAdd(row, 1.U, max_rows)
    val next_c = Mux(row === max_rows - 1.U, floorAdd(col, col_bytes, max_cols), col)
    val next_t = Mux(row === max_rows - 1.U && col === max_cols - col_bytes, floorAdd(tile, 1.U, max_tiles), tile)

    tile := next_t
    col := next_c
    row := next_r
  }
*/

  io.req.ready := false.B
  io.busy := state =/= idle
  when (state === idle) {
      req := io.req.bits
      tile := 0.U
      row := 0.U
      col := 0.U
    io.req.ready := true.B
      when(io.req.fire){
        io.busy := true.B
        state := memcpy
      }
  }.elsewhen(state === memcpy) {
      io.out.valid := true.B
      when (io.out.fire) {
        //state := memcpying
        //increment()
        val next_c =floorAdd(col, col_bytes, max_cols)
        val next_r = floorAdd(row, 1.U, max_rows, next_c === 0.U)
        val next_t = floorAdd(tile, 1.U, max_tiles, next_r === 0.U && next_c === 0.U)

        row := next_r
        col := next_c
        tile := next_t

        when (next_r === 0.U && next_c === 0.U && next_t === 0.U) {
          state := idle
          //io.req.ready := true.B
        }
        //state := Mux(last_iteration, idle, memcpy)
        //when(!last_iteration){
        //  increment()
        //}
      }
  }
}

