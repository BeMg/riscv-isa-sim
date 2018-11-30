
int element_size = 8;
int element_num = int(32 / element_size);

int rs1[element_num];
int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xff;
}

int rst[element_num];

for (int i=0; i<element_num; i++) {
    if( ((rs1[i]&0x80) != rs2[i]&0x80) && ((rs1[i] - rs2[i])&0x80 != (rs1[i]&0x80)) ) { 
        if ((rs1[i]&0x80) == 0) {
            rst[i] = 0b01111111;
        } else {
            rst[i] = 0b10000000;
        }
    } else {
        rst[i] = (rs1[i]-rs2[i]) & 0xff;
    }
}

int rst_sum = 0;

for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | (rst[i] << (element_size * (element_num-(i+1)))); 
}

WRITE_RD(rst_sum);

// Count SIMD insn

SIMD_ADD1;
SIMD_NOPK_ADD1;