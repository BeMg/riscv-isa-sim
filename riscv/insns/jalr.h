reg_t tmp = npc;
set_pc((RS1 + insn.i_imm()) & ~reg_t(1));
WRITE_RD(tmp);
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
