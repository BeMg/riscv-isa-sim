switch (STATE.prv)
{
  case PRV_U: throw trap_user_ecall();
  case PRV_S: throw trap_supervisor_ecall();
  case PRV_M: throw trap_machine_ecall();
  default: abort();
}
ALL_INSN_ADD1;


ALL_INSN_count;
ALL_INSN_cycle(1);
