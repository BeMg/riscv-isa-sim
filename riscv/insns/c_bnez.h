require_extension('C');
if (RVC_RS1S != 0)
  set_pc(pc + insn.rvc_b_imm());
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
