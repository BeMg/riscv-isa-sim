require_privilege(get_field(STATE.mstatus, MSTATUS_TW) ? PRV_M : PRV_S);
wfi();
ALL_INSN_ADD1;


ALL_INSN_count;
ALL_INSN_cycle(1);
