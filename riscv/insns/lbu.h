WRITE_RD(MMU.load_uint8(RS1 + insn.i_imm()));
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
