require_extension('F');
require_fp;
WRITE_FRD(f32(MMU.load_uint32(RS1 + insn.i_imm())));
ALL_INSN_ADD1;


ALL_INSN_count;
ALL_INSN_cycle(1);
