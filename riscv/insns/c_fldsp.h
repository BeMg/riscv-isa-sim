require_extension('C');
require_extension('D');
require_fp;
WRITE_FRD(f64(MMU.load_uint64(RVC_SP + insn.rvc_ldsp_imm())));
ALL_INSN_ADD1;


ALL_INSN_count;
ALL_INSN_cycle(1);
