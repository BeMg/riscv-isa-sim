require_extension('C');
require(insn.rvc_rs1() != 0);
set_pc(RVC_RS1 & ~reg_t(1));
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
