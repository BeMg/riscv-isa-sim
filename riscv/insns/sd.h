require_rv64;
MMU.store_uint64(RS1 + insn.s_imm(), RS2);
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
