require_extension('C');
require_extension('D');
require_fp;
MMU.store_uint64(RVC_RS1S + insn.rvc_ld_imm(), RVC_FRS2S.v[0]);
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
