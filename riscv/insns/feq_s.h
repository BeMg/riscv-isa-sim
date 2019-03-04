require_extension('F');
require_fp;
WRITE_RD(f32_eq(f32(FRS1), f32(FRS2)));
set_fp_exceptions;
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
