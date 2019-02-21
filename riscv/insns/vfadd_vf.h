int vl = STATE.vl;
vreg_t a = VRS1;
vreg_t b = VRS2;

vreg_t rst;
fprintf(stderr, "Warning: GPR register should change to FPR\n");

for(int i=0; i<vl; i++) {
    float tmp_a = RS1;
    float tmp_b = INTTOFLOAT(b.data[i]);
    float tmp_rst = tmp_a + tmp_b;
    rst.data[i] = FLOATTOINT(tmp_rst);
}

for(int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}


WRITE_VRD(rst);