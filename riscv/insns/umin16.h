
int element_size = 16;
int element_num = int(64 / element_size);

unsigned int rs1[element_num];
unsigned int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
}

int rst[element_num];

for(int i=0; i<element_num; i++) {
    rst[i] = (rs1[i] > rs2[i]) ? rs2[i] : rs1[i];
    rst[i] = rst[i] & 0xffff;
}

// rst[0] = ((rs1[0]>rs2[0]) ? rs2[0] : rs1[0]) & 0xffff;
// rst[1] = ((rs1[1]>rs2[1]) ? rs2[1] : rs1[1]) & 0xffff;
// rst[2] = (rs1[2]+rs2[2]) & 0xffff;
// rst[3] = (rs1[3]+rs2[3]) & 0xffff;

long long rst_sum = 0;

for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | ((long long)rst[i] << (element_size * (element_num-(i+1)))); 
}

WRITE_RD(rst_sum);

ALL_INSN_ADD1;



ALL_INSN_count;
P_EXT_count;
P_EXT_cycle(3);
ALL_INSN_cycle(3);
