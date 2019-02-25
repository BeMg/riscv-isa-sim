
int element_size = 8;
int element_num = int(64 / element_size);

int rs1[element_num];
int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xff;
}

int rst[element_num];

int sa = RS2 & 0b111; // RS2[2:0]

bool overflow_flag = false;

int mask_for_underflow = 0xff << (8 - sa);

for(int i=0; i<element_num; i++) {
    if(sa != 0) {
        rst[i] = rs1[i] << sa;
        if( !(rs1[i] & 0x80) && rst[i] > 0x7f) {
            rst[i] = 0x7f;
            overflow_flag = true;
        } else if((rs1[i] & 0x80) && (mask_for_underflow == (rs1[i]&mask_for_underflow))) {
            rst[i] = 0x80;
            overflow_flag = true;
        }
        rst[i] = rst[i] & 0xff;
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


ALL_INSN_count;
ALL_INSN_cycle(1);
P_EXT_count;
P_EXT_cycle(1);
