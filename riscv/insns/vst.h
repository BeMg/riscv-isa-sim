int64_t vl = STATE.vl;
vreg_t src = VRRD;

for (int32_t i=0; i<vl; i++) {
    // a Int is 4 bytes, so each step move 4
    MMU.store_int32(RS1 + insn.i_imm() + 4 * i, src.data[i]);
}

for (int i=vl; i<MAXVL; i++) {
    src.data[i] = 0;
}
