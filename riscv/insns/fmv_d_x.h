require_extension('D');
require_rv64;
require_fp;
WRITE_FRD(f64(RS1));
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
