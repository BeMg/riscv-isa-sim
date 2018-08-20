vreg_t rs1 = VRS1;
vreg_t rs2 = VRS2;
vreg_t rst;
int vl = STATE.vl;

for(int i=0; i < vl; i++) {
    rst.data[i] = rs1.data[i] + rs2.data[i];
}

<<<<<<< HEAD
for (int i=vl; i<MAXVL; i++) {
=======
for (int i=vl; i<NVPR; i++) {
>>>>>>> 0f934bbb8de8f9da6faef3c894dfec207b356378
    rst.data[i] = 0;
}

WRITE_VRD(rst);