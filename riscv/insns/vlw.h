int64_t vl = STATE.vl;
vreg_t rst;

int offset = insn.i_imm();

for (int i=0; i<vl; i++) {
    rst.data[i] = MMU.load_int32(RS1 + 4 * i + insn.i_imm());
}
for (int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}


WRITE_VRD(rst);
ALL_INSN_ADD1;
