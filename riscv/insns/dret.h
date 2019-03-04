require_privilege(PRV_M);
set_pc_and_serialize(STATE.dpc);
p->set_privilege(STATE.dcsr.prv);

/* We're not in Debug Mode anymore. */
STATE.dcsr.cause = 0;

if (STATE.dcsr.step)
  STATE.single_step = STATE.STEP_STEPPING;
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
