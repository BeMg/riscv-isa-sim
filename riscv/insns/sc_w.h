require_extension('A');
if (MMU.check_load_reservation(RS1))
{
  MMU.store_uint32(RS1, RS2);
  WRITE_RD(0);
}
else
  WRITE_RD(1);

MMU.yield_load_reservation();
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
