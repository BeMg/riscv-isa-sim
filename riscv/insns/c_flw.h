require_extension('C');
if (xlen == 32) {
  require_extension('F');
  require_fp;
  WRITE_RVC_FRS2S(f32(MMU.load_uint32(RVC_RS1S + insn.rvc_lw_imm())));
} else { // c.ld
  WRITE_RVC_RS2S(MMU.load_int64(RVC_RS1S + insn.rvc_ld_imm()));
}
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
