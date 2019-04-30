require_extension('C');
if (xlen == 32) {
  reg_t tmp = npc;
  set_pc(pc + insn.rvc_j_imm());
  WRITE_REG(X_RA, tmp);
} else { // c.addiw
  require(insn.rvc_rd() != 0);
  WRITE_RD(sext32(RVC_RS1 + insn.rvc_imm()));
}
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
