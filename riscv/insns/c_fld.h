require_extension('C');
require_extension('D');
require_fp;
WRITE_RVC_FRS2S(f64(MMU.load_uint64(RVC_RS1S + insn.rvc_ld_imm())));
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
