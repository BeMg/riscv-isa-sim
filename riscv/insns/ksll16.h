
int element_size = 16;
int element_num = int(32 / element_size);

int rs1[element_num];
int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
}

int rst[element_num];

int sa = RS2 & 0b1111; // RS2[3:0]

bool overflow_flag = false;

for(int i=0; i<element_num; i++) {
    if(sa != 0) {
        rst[i] = (rs1[i] << sa);
        if( !(rs1[i] & 0x8000) && rst[i] > 0x7fff) {
            rst[i] = 0x7fff;
            overflow_flag = true;
        } else if((rs1[i] & 0x8000) && rst[i] > 32768) {
            rst[i] = 0x8000;
            overflow_flag = true;
        }
        rst[i] = rst[i] & 0xffff;
    } else {
        // rd = rs1
        rst[i] = rs1[i];
    }
}


int rst_sum = 0;

for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | (rst[i] << (element_size * (element_num-(i+1)))); 
}


WRITE_RD(rst_sum);

// Count SIMD insn

SIMD_ADD1;
SIMD_NOPK_ADD1;ALL_INSN_ADD1;
