int64_t vl = STATE.vl;
vreg_t rst;
for (int32_t i=0; i<vl; i++) {
    rst.data[i] = MMU.load_int32(RS1 + 4 *i);
}
for (int i=vl; i<NVPR; i++) {
    rst.data[i] = 0;
}

WRITE_VRD(rst);
