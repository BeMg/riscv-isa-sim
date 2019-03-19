
int element_size = 16;
int element_num = int(64 / element_size);

int rs1[element_num];
int rs2[element_num];

bool overflow_flag = false;

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
}

int rst[element_num];


for (int i=0; i<element_num; i++) {
    // Maybe only this case 0x8000 * 0x8000 will overflow.
    if(rs1[i]!=0x8000 || rs2[i] != 0x8000) {
        int tmp_rs1 = rs1[i];
        int tmp_rs2 = rs2[i];
        // extend zero for mul on negative number
        if(tmp_rs1 & 0x8000) {
            tmp_rs1 = tmp_rs1 | 0xffff0000;
        }
        if(tmp_rs2 & 0x8000) {
            tmp_rs2 = tmp_rs2 | 0xffff0000;
        }

        rst[i] = (tmp_rs1 * tmp_rs2) >> 15;
    } else {
        rst[i] = 0x7fff;
        overflow_flag = true;
    }
    rst[i] = rst[i] & 0xffff;
}


long long rst_sum = 0;


for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | ((long long)rst[i] << (element_size * (element_num-(i+1)))); 
}

// fprintf(stderr, "Warning: add16 have some problem, this insn will exec but no affect register content\nThis Insn result is %d\n", rst_sum);

WRITE_RD(rst_sum);

// Count SIMD insn

SIMD_ADD1;
SIMD_NOPK_ADD1;ALL_INSN_ADD1;







ALL_INSN_count;
P_EXT_count;
P_EXT_cycle(1);
ALL_INSN_cycle(1);
