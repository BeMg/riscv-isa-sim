require_rv64;
WRITE_RD(sext32(int32_t(RS1) >> SHAMT));
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
