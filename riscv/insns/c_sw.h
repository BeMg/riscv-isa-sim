require_extension('C');
MMU.store_uint32(RVC_RS1S + insn.rvc_lw_imm(), RVC_RS2S);
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
