vreg_t rst = VRRD;
vreg_t source1 = VRS2;

int offset = insn.rs1();
int vl = STATE.vl;

for(int i=0; i<vl; i++) {
    int new_posi = i+offset;
    if(new_posi < 0 || new_posi >= vl) {

    } else {
        rst.data[new_posi] = source1.data[i];
    }
}

WRITE_VRD(rst);







ALL_INSN_count;
V_EXT_count;
V_EXT_cycle(3);
ALL_INSN_cycle(3);
