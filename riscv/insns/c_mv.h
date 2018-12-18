require_extension('C');
require(insn.rvc_rs2() != 0);
WRITE_RD(RVC_RS2);
ALL_INSN_ADD1;
