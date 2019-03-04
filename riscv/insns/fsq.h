require_extension('Q');
require_fp;
MMU.store_float128(RS1 + insn.s_imm(), FRS2);
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
