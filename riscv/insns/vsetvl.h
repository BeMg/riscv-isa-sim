WRITE_RD(sext_xlen(RS1 + 0));

// set vl register
WRITE_VL(RS1);

// set sew register
WRITE_VTYPE(RS2);


ALL_INSN_ADD1;








ALL_INSN_count;
V_EXT_count;
V_EXT_cycle(3);
ALL_INSN_cycle(3);
