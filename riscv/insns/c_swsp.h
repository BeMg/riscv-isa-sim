require_extension('C');
MMU.store_uint32(RVC_SP + insn.rvc_swsp_imm(), RVC_RS2);
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
