require_extension('C');
require(insn.rvc_addi4spn_imm() != 0);
WRITE_RVC_RS2S(sext_xlen(RVC_SP + insn.rvc_addi4spn_imm()));
ALL_INSN_ADD1;



ALL_INSN_count;
ALL_INSN_cycle(1);
