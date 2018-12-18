int element_size = 16;
int element_num = int(32 / element_size);

int rs1[element_num];
int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
}

int rd = 0;
rd = RD;

// TODO: Check 16 bits mul run on 32 bits is ok.
int old_rd = rd;
int tmp = ((rs1[0] * rs2[0]) + (rs1[1] * rs2[1]));


rd = rd + tmp;

bool overflow_flag = false;

if (old_rd > 0 && tmp > 0 && rd < 0) {
    overflow_flag = true;
    rd = 2147483647;
}
if (old_rd < 0 && tmp < 0 && rd > 0) {
    overflow_flag = true;
    rd = -2147483648;
}

// Maybe set some CSR when overflow_flag is true.

WRITE_RD(rd);

// Count SIMD insn

SIMD_ADD1;
SIMD_NOPK_ADD1;ALL_INSN_ADD1;
