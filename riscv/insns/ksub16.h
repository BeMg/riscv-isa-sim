int element_size = 16;
int element_num = int(64 / element_size);

int rs1[element_num];
int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
}

int rst[element_num];


// Overflow will happened when two operand have same sign and result's sign is diff from operand.
// For example: positive add positive -> negative
//              negative add negative -> positive
// P.S. 0x8000 is mask for take number first bits to eheck sign.

for (int i=0; i<element_num; i++) {
    if( ((rs1[i]&0x8000) != rs2[i]&0x8000) && ((rs1[i] - rs2[i])&0x8000 != (rs1[i]&0x8000)) ) { 
        if ((rs1[i]&0x8000) == 0) {
            rst[i] = 0b0111111111111111;
        } else {
            rst[i] = 0b1000000000000000;
        }
    } else {
        rst[i] = (rs1[i]-rs2[i]) & 0xffff;
    }
}
// rst[0] = (rs1[0]+rs2[0]) & 0xffff;
// rst[1] = (rs1[1]+rs2[1]) & 0xffff;

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
