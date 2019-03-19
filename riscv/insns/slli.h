require(SHAMT < xlen);
WRITE_RD(sext_xlen(RS1 << SHAMT));
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
