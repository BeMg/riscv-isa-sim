vreg_t rst;
vreg_t rs1 = VRS1;
vreg_t rs2 = VRS2;
int vl = STATE.vl;

for(int i=0; i<vl; i++) {
    rst.f_data[i] = rs1.f_data[i] + rs2.f_data[i];
}

for(int i=vl; i<MAXVL; i++) {
    rst.f_data[i] = 0;
}

WRITE_VRD(rst);