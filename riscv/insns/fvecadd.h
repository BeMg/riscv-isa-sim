int len = GETVEC_LEN;

// float vec1[len];
// float vec2[len];


// for(int i=0; i<len; i++) {
//     int tmp = MMU.load_int32(RS1 + 4 * i);
//     vec1[i] = *((float *)(&tmp));
// }

// for(int i=0; i<len; i++) {
//     int tmp = MMU.load_int32(RS2 + 4 * i);
//     vec2[i] = *((float *)(&tmp));
// }


// float vec3[len];

// for(int i=0; i<len; i++) {
//     vec3[i] = vec1[i] + vec2[i];
// }

// for(int i=0; i<len; i++) {
//     int tmp = *((int *)(&vec3[i]));
//     MMU.store_uint32(RD + 4 * i, tmp);
// }


float *vec1;
float *vec2;
float *vec3 = (float*) malloc(sizeof(float) * len);

vec1 = (float*)MMU.many_load_int32(RS1, len);
vec2 = (float*)MMU.many_load_int32(RS2, len);

for(int i=0; i<len; i++) {
    vec3[i] = vec1[i] + vec2[i];
}

MMU.many_store_int32(RD, len, (uint32_t*)vec3);

free(vec1);
free(vec2);
free(vec3);














ALL_INSN_count;
ALL_INSN_cycle(1);
