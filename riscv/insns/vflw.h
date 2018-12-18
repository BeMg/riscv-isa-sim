
int sz = 4;

// TODO: need to check this register is support float.
// TODO: check this register is enable.

int idx = RS1 + insn.i_imm();

int vl = STATE.vl;

vreg_t tmp;

for(int i=0; i<vl; i++) {
    int32_t value = MMU.load_int32(idx);
    tmp.f_data[i] = INTTOFLOAT(value);
    idx = idx + sz;
}

WRITE_VRD(tmp);ALL_INSN_ADD1;
