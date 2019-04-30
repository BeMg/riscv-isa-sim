require_extension('A');
MMU.acquire_load_reservation(RS1);
WRITE_RD(MMU.load_int32(RS1));
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
