require_extension('C');
require(insn.rvc_rs2() != 0);
WRITE_RD(sext_xlen(RVC_RS1 + RVC_RS2));
ALL_INSN_ADD1;
