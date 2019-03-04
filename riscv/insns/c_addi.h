require_extension('C');
WRITE_RD(sext_xlen(RVC_RS1 + insn.rvc_imm()));
ALL_INSN_ADD1;




ALL_INSN_count;
ALL_INSN_cycle(1);
