
int element_size = 8;
int element_num = int(64 / element_size);

int rs1[element_num];
int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xff;
}

int rst[element_num];

for(int i=0; i<element_num; i++) {
    rst[i] = ((rs1[i]-rs2[i]) >> 1) & 0xff;
}

long long rst_sum = 0;

for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | ((long long)rst[i] << (element_size * (element_num-(i+1)))); 
}

WRITE_RD(rst_sum);

// Count SIMD insn

SIMD_ADD1;
SIMD_NOPK_ADD1;ALL_INSN_ADD1;














ALL_INSN_count;
P_EXT_count;
P_EXT_cycle(1);
ALL_INSN_cycle(1);
