require_privilege(get_field(STATE.mstatus, MSTATUS_TVM) ? PRV_M : PRV_S);
MMU.flush_tlb();
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
