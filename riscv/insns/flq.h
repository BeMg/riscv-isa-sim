require_extension('Q');
require_fp;
WRITE_FRD(MMU.load_float128(RS1 + insn.i_imm()));
ALL_INSN_ADD1;


ALL_INSN_count;
ALL_INSN_cycle(1);
