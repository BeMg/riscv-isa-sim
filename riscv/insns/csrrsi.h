bool write = insn.rs1() != 0;
int csr = validate_csr(insn.csr(), write);
reg_t old = p->get_csr(csr);
if (write) {
  p->set_csr(csr, old | insn.rs1());
}
WRITE_RD(sext_xlen(old));
serialize();
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);
