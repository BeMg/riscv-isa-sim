
int64_t vl = STATE.vl;
vreg_t src = VRS3;

int offset = insn.imm3_st();

for (int i=0; i<vl; i++) {
    // a Int is 4 bytes, so each step move 4
    MMU.store_uint32(RS1 + 4 * i + 4 * offset, src.data[i]);
}

for (int i=vl; i<MAXVL; i++) {
    src.data[i] = 0;
}
