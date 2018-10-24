
int64_t vl = STATE.vl;
vreg_t src = VRS3;

int offset = insn.imm3_st();

for (int i=0; i<vl; i++) {
    // a Int is 4 bytes, so each step move 4
    MMU.store_uint16(RS1 + 2 * i + 2 * offset, src.data[i]);
}

for (int i=vl; i<MAXVL; i++) {
    src.data[i] = 0;
}
