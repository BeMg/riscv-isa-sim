require_extension('A');
require_rv64;
MMU.acquire_load_reservation(RS1);
WRITE_RD(MMU.load_int64(RS1));
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
