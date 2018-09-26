int element_size = 16;
int element_num = int(32 / element_size);

unsigned int rs1[element_num];
unsigned int rs2[element_num];

for(int i=0; i<element_num; i++) {
    rs1[i] = ((RS1 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
    rs2[i] = ((RS2 << element_size*i) >> element_size*(element_num-1)) & 0xffff;
}

int rst[element_num];

for (int i=0; i<element_num; i++) {
    int min_num = (rs1[i] > rs2[i]) ? rs2[i] : rs1[i];
    if(rs1[i]+rs2[i] < min_num) { 
        rst[i] = 0xffffffff;
    } else {
        rst[i] = (rs1[i]+rs2[i]) & 0xffff;
    }
}

int rst_sum = 0;

for (int i=0; i<element_num; i++) {
    rst_sum = rst_sum | (rst[i] << (element_size * (element_num-(i+1)))); 
}

WRITE_RD(rst_sum);
