int len = GETVEC_LEN;

float vec1[len];
float vec2[len];

for(int i=0; i<len; i++) {
    int tmp = MMU.load_int32(RS1 + 4 * i);
    vec1[i] = *((float *)(&tmp));
}


for(int i=0; i<len; i++) {
    vec2[i] = 1 / (1 + EXP(-vec1[i]));
}

for(int i=0; i<len; i++) {
    int tmp = *((int *)(&vec2[i]));
    MMU.store_uint32(RD + 4 * i, tmp);
}