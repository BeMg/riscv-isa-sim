reg_t tmp = npc;
set_pc(JUMP_TARGET);
WRITE_RD(tmp);
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
