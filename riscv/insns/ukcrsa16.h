int element_size = 16;
int element_num = int(32 / element_size);

unsigned int rs1[element_num];
unsigned int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
}

int rst[element_num];


unsigned int max_num = (rs1[0] > rs2[1]) ? rs1[0] : rs2[1];
if(rs1[0]-rs2[1] > max_num) { 
    rst[0] = 0xffff;
} else {
    rst[0] = (rs1[0]-rs2[1]) & 0xffff;
}

unsigned int min_num = (rs1[1] > rs2[0]) ? rs2[0] : rs1[1];
if(rs1[1] + rs2[0] < min_num) { 
    rst[1] = 0xffff;
} else {
    rst[1] = (rs1[1]+rs2[0]) & 0xffff;
}

int rst_sum = 0;

for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | (rst[i] << (element_size * (element_num-(i+1)))); 
}

WRITE_RD(rst_sum);

// Count SIMD insn

SIMD_ADD1;
SIMD_NOPK_ADD1;