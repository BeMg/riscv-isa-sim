
int element_size = 8;
int element_num = int(32 / element_size);

unsigned int rs1[element_num];
unsigned int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xff;
}

int rst[element_num];

rst[0] = ((rs1[0]+rs2[0]) >> 1) & 0xff;
rst[1] = ((rs1[1]+rs2[1]) >> 1) & 0xff;
rst[2] = ((rs1[2]+rs2[2]) >> 1) & 0xff;
rst[3] = ((rs1[3]+rs2[3]) >> 1) & 0xff;

int rst_sum = 0;

for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | (rst[i] << (element_size * (element_num-(i+1)))); 
}

WRITE_RD(rst_sum);

ALL_INSN_ADD1;
