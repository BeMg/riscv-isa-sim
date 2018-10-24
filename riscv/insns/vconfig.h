int csr = CSR;

STATE.vregmax = csr & 0b11111;
STATE.vemaxw  = (csr >> 5) & 0b11;


