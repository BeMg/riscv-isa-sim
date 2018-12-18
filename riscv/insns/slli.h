require(SHAMT < xlen);
WRITE_RD(sext_xlen(RS1 << SHAMT));
ALL_INSN_ADD1;
