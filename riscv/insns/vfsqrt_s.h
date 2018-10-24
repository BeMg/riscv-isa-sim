vreg_t rs1 = VRS1;
vreg_t rs2 = VRS2;
vreg_t rst;
int vl = STATE.vl;
int mask = insn.mask_lo();

bool enable[MAXVL];
vreg_t v_mask = READ_VREG(0);

for(int i=0; i<MAXVL; i++) {
    enable[i] = ((mask >> 1) == 0) || ((mask&0b1) == (v_mask.data[i]&0b1));
}

switch (mask) {
    case 0b00:
        for(int i=0; i < vl; i++) {
            float tmp =  *(float *)&rs1.data[0];
            tmp = SQRT(tmp);
            rst.data[i] = *(int *)&tmp;
        }
        break;
    case 0b01:
    case 0b10:
    case 0b11:
        for(int i=0; i < vl; i++) {
            float tmp = enable[i] ? (*(float *)&rs1.data[i]) : 0;
            tmp = SQRT(tmp);
            rst.data[i] = *(int *)&tmp;
        }
        break;
    default:
        fprintf(stderr, "ERROR!!! mask value must between [0, 3]\n");
        break;
}

for (int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}

WRITE_VRD(rst);
