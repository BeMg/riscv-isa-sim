int64_t vl = STATE.vl;
vreg_t rst;
for (int32_t i=0; i<vl; i++) {
    rst.data[i] = MMU.load_int32(RS1 + 4 *i);
}
<<<<<<< HEAD
for (int i=vl; i<MAXVL; i++) {
=======
for (int i=vl; i<NVPR; i++) {
>>>>>>> 0f934bbb8de8f9da6faef3c894dfec207b356378
    rst.data[i] = 0;
}

WRITE_VRD(rst);
