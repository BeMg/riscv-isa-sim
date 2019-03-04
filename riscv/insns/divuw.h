require_extension('M');
require_rv64;
reg_t lhs = zext32(RS1);
reg_t rhs = zext32(RS2);
if(rhs == 0)
  WRITE_RD(UINT64_MAX);
else
  WRITE_RD(sext32(lhs / rhs));
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
