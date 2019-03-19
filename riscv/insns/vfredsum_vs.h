int vl = STATE.vl;
vreg_t a = VRS1;
vreg_t b = VRS2;

reg_t rst = 0;

fprintf(stderr, "Warning: Now result store with GPR(int) not FPR(float)\n");

for(int i=0; i<vl; i++) {
    float tmp_a = INTTOFLOAT(a.data[i]);
    float tmp_b = INTTOFLOAT(b.data[0]);
    float tmp_rst = tmp_a + tmp_b;
    rst += tmp_rst;
}

WRITE_RD(sext_xlen(rst));











ALL_INSN_count;
V_EXT_count;
V_EXT_cycle(3);
ALL_INSN_cycle(3);
