require_extension('F');
require_fp;
MMU.store_uint32(RS1 + insn.s_imm(), FRS2.v[0]);
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
