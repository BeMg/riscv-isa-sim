int csr = CSR;

STATE.vregmax = csr & 0b11111;
STATE.vemaxw  = (csr >> 5) & 0b11;


ALL_INSN_ADD1;
