require_extension('Q');
require_fp;
softfloat_roundingMode = RM;
WRITE_FRD(f128_mulAdd(f128(FRS1), f128(FRS2), f128(FRS3)));
set_fp_exceptions;
ALL_INSN_ADD1;
