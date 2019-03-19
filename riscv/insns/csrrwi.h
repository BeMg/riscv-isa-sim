int csr = validate_csr(insn.csr(), true);
reg_t old = p->get_csr(csr);
p->set_csr(csr, insn.rs1());
WRITE_RD(sext_xlen(old));
serialize();
ALL_INSN_ADD1;







ALL_INSN_count;
ALL_INSN_cycle(1);
