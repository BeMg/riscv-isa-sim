int vl = STATE.vl;
int sew = GET_SEW;
vreg_t rst = VRRD;

uint32_t tmp_rst[vl];


for (int i=0; i<vl; i++) {
    tmp_rst[i] = rst.data[i];
}

MMU.many_store_int32(RS1+insn.i_imm(), vl, (uint32_t*)tmp_rst);





ALL_INSN_count;
V_EXT_count;
V_EXT_cycle(6);
ALL_INSN_cycle(6);
