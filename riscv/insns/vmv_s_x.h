vreg_t rst = VRRD;

rst.data[0] = RS1;

WRITE_VRD(rst);






ALL_INSN_count;
ALL_INSN_cycle(1);
V_EXT_count;
V_EXT_cycle(3);
