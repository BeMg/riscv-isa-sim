require_extension('M');
// RD = RD + RS1 * RS2
reg_t tmp = sext_xlen(RS1 * RS2);
WRITE_RD(sext_xlen(READ_REG(insn.rd()) + tmp));
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
