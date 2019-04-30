require_rv64;
WRITE_RD(sext32(insn.i_imm() + RS1));
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
