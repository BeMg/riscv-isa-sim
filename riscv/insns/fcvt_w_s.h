require_extension('F');
require_fp;
softfloat_roundingMode = RM;
WRITE_RD(sext32(f32_to_i32(f32(FRS1), RM, true)));
set_fp_exceptions;
ALL_INSN_ADD1;


ALL_INSN_count;
ALL_INSN_cycle(1);
