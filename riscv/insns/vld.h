int64_t vl = STATE.vl;
vreg_t rst;

int offset = insn.imm3_ld();

for (int i=0; i<vl; i++) {
    rst.data[i] = MMU.load_int64(RS1 + 8 * i + 8 * offset);
}
for (int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}

WRITE_VRD(rst);
ALL_INSN_ADD1;
