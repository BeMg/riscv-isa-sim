require_extension('C');
set_pc(pc + insn.rvc_j_imm());
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
