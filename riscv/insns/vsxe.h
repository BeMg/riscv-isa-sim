
int vl = STATE.vl;
int sew = GET_SEW;
vreg_t rst = VRRD;

vreg_t vs2 = VRS2;
// Need Check SEW to get the data width

int max = 0;
for(int i=0; i<vl; i++) {
    if(max < vs2.data[i]) {
        max = vs2.data[i];
    }
}

uint8_t  *tmp_8;
uint16_t *tmp_16;
uint32_t *tmp_32;
uint64_t *tmp_64;

switch(sew) {
    case 0b000:
        tmp_8 = (uint8_t*)MMU.many_load_int8(RS1, max+1);
        break;
    case 0b001:
        tmp_16 = (uint16_t*)MMU.many_load_int16(RS1, max+1);
        break;
    case 0b010:
        tmp_32 = (uint32_t*)MMU.many_load_int32(RS1, max+1);
        break;
    case 0b011:
        tmp_64 = (uint64_t*)MMU.many_load_int64(RS1, max+1);
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


uint64_t tmp_rst[max+1];

for(int i=0; i<vl; i++) {
    switch(sew) {
        case 0b000:
            ((uint8_t*)tmp_8)[vs2.data[i]] = rst.data[i];
            break;
        case 0b001:
            ((uint16_t*)tmp_16)[vs2.data[i]] = rst.data[i];
            break;
        case 0b010:
            ((uint32_t*)tmp_32)[vs2.data[i]] = rst.data[i];
            break;
        case 0b011:
            ((uint64_t*)tmp_64)[vs2.data[i]] = rst.data[i];
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
        MMU.many_store_int8(RS1, max+1, (uint8_t*)tmp_8);
        break;
    case 0b001:
        MMU.many_store_int16(RS1, max+1, (uint16_t*)tmp_16);
        break;
    case 0b010:
        MMU.many_store_int32(RS1, max+1, (uint32_t*)tmp_32);
        break;
    case 0b011:
        MMU.many_store_int64(RS1, max+1, (uint64_t*)tmp_64);
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
ALL_INSN_cycle(1);
