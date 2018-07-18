require_extension('V');
int vl = STATE.vl;
vreg_t rst;
for (int i=0; i<vl; i++) {
    rst.data[i] = MMU.load_int64(RS1 + insn.i_imm() + i);    
}
WRITE_VRD(rst);
