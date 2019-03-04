int vl = STATE.vl;
vreg_t a = VRS2;
vreg_t b = VRS1;

reg_t rst = 0;

vreg_t mask = READ_VREG(0);
int mask_flag = VMASK;


for(int i=0; i<vl; i++) {
    int tmp_rst = a.data[i] + b.data[0];

    if(mask_flag) {
        if(mask.data[i]&1) {
            rst += tmp_rst;
        } else {
            rst += 0;
        }
    } else {
        rst += tmp_rst;
    }
}


WRITE_RD(sext_xlen(rst));







ALL_INSN_count;
V_EXT_count;
V_EXT_cycle(3);
ALL_INSN_cycle(3);
