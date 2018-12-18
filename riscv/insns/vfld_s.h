int32_t value = MMU.load_int32(RS1 + insn.i_imm());

vreg_t rst;

for(int i=0; i<STATE.vl; i++) {
    rst.f_data[i] = INTTOFLOAT(value);
}
for(int i=STATE.vl; i<MAXVL; i++) {
    rst.f_data[i] = 0;
}

WRITE_VRD(rst);ALL_INSN_ADD1;
