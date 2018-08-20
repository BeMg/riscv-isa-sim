uint64_t imm20 = insn.l_imm();

if (imm20 == 0) {
    WRITE_VREGMAX(0); // represent vector unit is disable
} else {
    WRITE_VREGMAX((imm20 << (64-5) >> (64-5)));
    WRITE_VEMAXW((imm20 << (64-7) >> (64-2)));
    // WRITE_VTYPEEN(); Not in spec QQ
    WRITE_VXCM((imm20 << (64-8) >> (64-1))); 
    WRITE_VXRM(2); // always set to 0b10
    WRITE_VL(MAXVL); // Set vl to MAXVL
}