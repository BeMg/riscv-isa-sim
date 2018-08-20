int64_t vl = STATE.vl;
vreg_t src = VRS1;

for (int i=0; i<vl; i++) {
    // a Int is 4 bytes, so each step move 4
    int tmp = FLOATTOINT(src.f_data[i]);
    MMU.store_int32(RS2 + insn.s_imm() + 4 * i, tmp);
}

for (int i=vl; i<MAXVL; i++) {
    src.f_data[i] = 0;
}
