
if (MAXVL > RS1) {
    WRITE_VL(RS1);
    WRITE_RD(sext_xlen(RS1));
} else {
    WRITE_VL(MAXVL);
    WRITE_RD(sext_xlen(MAXVL));
}
ALL_INSN_ADD1;
