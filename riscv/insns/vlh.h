int64_t vl = STATE.vl;
vreg_t rst;

int offset = insn.imm3_ld();

for (int i=0; i<vl; i++) {
    rst.data[i] = MMU.load_int16(RS1 + 2 * i + 2 * offset);
}
for (int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}

WRITE_VRD(rst);
