require_extension('F');
require_rv64;
require_fp;
softfloat_roundingMode = RM;
WRITE_FRD(ui64_to_f32(RS1));
set_fp_exceptions;
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
