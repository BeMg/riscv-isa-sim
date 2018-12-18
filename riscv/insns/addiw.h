require_rv64;
WRITE_RD(sext32(insn.i_imm() + RS1));
ALL_INSN_ADD1;
