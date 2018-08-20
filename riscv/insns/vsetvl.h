int64_t tmp = RS1 > MAXVL ? MAXVL: RS1; // setvl result is limited by min(rs1, MAXVL)
 
WRITE_RD(sext_xlen(tmp));
WRITE_VL(sext_xlen(tmp));