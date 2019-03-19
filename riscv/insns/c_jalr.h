require_extension('C');
require(insn.rvc_rs1() != 0);
reg_t tmp = npc;
set_pc(RVC_RS1 & ~reg_t(1));
WRITE_REG(X_RA, tmp);
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
