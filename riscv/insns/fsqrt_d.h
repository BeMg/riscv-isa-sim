require_extension('D');
require_fp;
softfloat_roundingMode = RM;
WRITE_FRD(f64_sqrt(f64(FRS1)));
set_fp_exceptions;
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
