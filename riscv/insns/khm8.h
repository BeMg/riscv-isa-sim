
int element_size = 8;
int element_num = int(32 / element_size);

int rs1[element_num];
int rs2[element_num];

bool overflow_flag = false;

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xff;
}



int rst[element_num];


for (int i=0; i<element_num; i++) {
    // Maybe only this case 0x80 * 0x80 will overflow.
    if(rs1[i]!=0x80 || rs2[i] != 0x80) {
        int tmp_rs1 = rs1[i];
        int tmp_rs2 = rs2[i];

        // extend zero for mul on negative number.
        if(tmp_rs1 & 0x80) {
            tmp_rs1 = tmp_rs1 | 0xff80;
        }
        if(tmp_rs2 & 0x80) {
            tmp_rs2 = tmp_rs2 | 0xff80;
        }
        
        rst[i] = (tmp_rs1 * tmp_rs2) >> 7;
    } else {
        rst[i] = 0x7f;
        overflow_flag = true;
    }
    rst[i] = rst[i] & 0xff;
}

int rst_sum = 0;

for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | (rst[i] << (element_size * (element_num-(i+1)))); 
}

WRITE_RD(rst_sum);

// Count SIMD insn

SIMD_ADD1;
SIMD_NOPK_ADD1;ALL_INSN_ADD1;
