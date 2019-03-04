WRITE_RD(sext_xlen(insn.u_imm() + pc));
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
