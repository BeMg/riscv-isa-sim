

/******
 * Need matrix size, and matrix start point: RD, RS1, RS2 
*******/


int mat1row = GETMAT1ROW;
int mat1col = GETMAT1COL;
int mat2row = GETMAT2ROW;
int mat2col = GETMAT2COL;

// Check mat1col == mat2row


int mat1_len = mat1row * mat1col;
int mat2_len = mat2row * mat2col;
// fprintf(stderr, "sharp: %d %d %d %d\n", mat1row, mat1col, mat2row, mat2col);
// fprintf(stderr, "len: %d %d\n", mat1_len, mat2_len);


float* mat1;
float* mat2;
float* mat3 = (float *)malloc(sizeof(float) * mat1row * mat2col);


mat1 = (float*)MMU.many_load_int32(RS1, mat1_len);

mat2 = (float*)MMU.many_load_int32(RS2, mat2_len);

// for(int i=0; i<mat1_len; i++) {
//     fprintf(stderr, "%f, ", mat1[i]);
// }
// fprintf(stderr, "\n");

// for(int i=0; i<mat2_len; i++) {
//     fprintf(stderr, "%f, ", mat2[i]);
// }
// fprintf(stderr, "\n");


// for(int i=0; i<mat1_len; i++) {
//     int tmp = MMU.load_int32(RS1 + 4 * i);
//     mat1[i] = *((float *)(&tmp));
// }


// for(int i=0; i<mat2_len; i++) {
//     int tmp = MMU.load_int32(RS2 + 4 * i);
//     mat2[i] = *((float *)(&tmp));
// }

// fprintf(stderr, "Finish\n");



// for(int i=0; i<mat1_len; i++) {
//     fprintf(stderr, "%f, ", mat1[i]);
// }

// fprintf(stderr, "\n");

// for(int i=0; i<mat2_len; i++) {
//     fprintf(stderr, "%f, ", mat2[i]);
// }

// fprintf(stderr, "\n");

// std::vector<float> mat3;
for(int i=0; i<mat1row * mat2col; i++) {
    mat3[i] = 0.0;
}

if(mat1col == mat2row) {
    for(int i=0; i<mat1row; i++) {
        for(int k=0; k<mat2col; k++) {
            for(int j=0; j<mat1col; j++) {
                mat3[i*mat1row+k] += mat1[i*mat1col+j] * mat2[j*mat2col+k];
            }
        }
    }
    

    MMU.many_store_int32(RD, mat1row * mat2col, (uint32_t*)mat3);


    
} else {
    fprintf(stderr, "ERROR: mat1col != mat2row\n");
}

free(mat1);
free(mat2);
free(mat3);

ALL_INSN_ADD1;
