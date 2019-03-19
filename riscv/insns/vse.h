
int vl = STATE.vl;
int sew = GET_SEW;
vreg_t rst = VRRD;

// Need Check SEW to get the data width

uint64_t tmp_rst[vl];

for(int i=0; i<vl; i++) {
    switch(sew) {
    case 0b000:
        ((uint8_t*)tmp_rst)[i] = rst.data[i];
        break;
    case 0b001:
        ((uint16_t*)tmp_rst)[i] = rst.data[i];
        break;
    case 0b010:
        ((uint32_t*)tmp_rst)[i] = rst.data[i];
        break;
    case 0b011:
        ((uint64_t*)tmp_rst)[i] = rst.data[i];
        break;
    case 0b100:            
    case 0b101:
    case 0b110:
    case 0b111:
        fprintf(stderr, "%d This SEW no support now\n", sew);
        break;
    default:
        break;
}

}

switch(sew) {
    case 0b000:
        MMU.many_store_int8(RS1, vl, (uint8_t*)tmp_rst);
        break;
    case 0b001:
        MMU.many_store_int16(RS1, vl, (uint16_t*)tmp_rst);
        break;
    case 0b010:
        MMU.many_store_int32(RS1, vl, (uint32_t*)tmp_rst);
        break;
    case 0b011:
        MMU.many_store_int64(RS1, vl, (uint64_t*)tmp_rst);
        break;
    case 0b100:            
    case 0b101:
    case 0b110:
    case 0b111:
        fprintf(stderr, "%d This SEW no support now\n", sew);
        break;
    default:
        break;
}














ALL_INSN_count;
V_EXT_count;
V_EXT_cycle(6);
ALL_INSN_cycle(6);
