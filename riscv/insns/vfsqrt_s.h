vreg_t rs1 = VRS1;
vreg_t rst;
int vl = STATE.vl;

for(int i=0; i < vl; i++) {
    float tmp = *(float *)&rs1.data[i];
    rst.data[i] = *(int *)&tmp;
}

for (int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}

WRITE_VRD(rst);