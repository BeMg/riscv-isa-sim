int vl = STATE.vl;
int sew = GET_SEW;

vreg_t rst;

uint32_t *tmp_32;
tmp_32 = (uint32_t*)MMU.many_load_int32(RS1+insn.i_imm(), vl);

for(int i=0; i<vl; i++) {
    rst.data[i] = tmp_32[i];
}

for(int i=vl; i<MAXVL; i++) {
    rst.data[i] = 0;
}

WRITE_VRD(rst);





ALL_INSN_count;
V_EXT_count;
V_EXT_cycle(6);
ALL_INSN_cycle(6);
