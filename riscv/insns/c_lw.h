require_extension('C');
WRITE_RVC_RS2S(MMU.load_int32(RVC_RS1S + insn.rvc_lw_imm()));
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
