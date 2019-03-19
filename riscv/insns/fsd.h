require_extension('D');
require_fp;
MMU.store_uint64(RS1 + insn.s_imm(), FRS2.v[0]);
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
