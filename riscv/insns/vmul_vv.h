int vl = STATE.vl;
vreg_t a = VRS1;
vreg_t b = VRS2;

vreg_t rst;

for(int i=0; i<vl; i++) {
    rst.data[i] = a.data[i] * b.data[i];
}

for(int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}

WRITE_VRD(rst);