int vl = STATE.vl;
vreg_t b = VRS2;

vreg_t rst;

for(int i=0; i<vl; i++) {
    rst.data[i] = RS1 * b.data[i];
}

for(int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}


WRITE_VRD(rst);


















ALL_INSN_count;
V_EXT_count;
V_EXT_cycle(3);
ALL_INSN_cycle(3);
