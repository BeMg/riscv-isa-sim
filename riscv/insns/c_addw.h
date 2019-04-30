require_extension('C');
require_rv64;
WRITE_RVC_RS1S(sext32(RVC_RS1S + RVC_RS2S));
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
