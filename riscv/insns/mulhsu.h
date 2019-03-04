require_extension('M');
if (xlen == 64)
  WRITE_RD(mulhsu(RS1, RS2));
else
  WRITE_RD(sext32((sext32(RS1) * reg_t((uint32_t)RS2)) >> 32));
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
