// fprintf(stderr,"In matmul\n");
// fprintf(stderr, "Check mat1: %dx%d\n", GETMAT1ROW, GETMAT1COL);
// fprintf(stderr, "Check mat2: %dx%d\n", GETMAT2ROW, GETMAT2COL);

int mat1row = GETMAT1ROW;
int mat1col = GETMAT1COL;
int mat2row = GETMAT2ROW;
int mat2col = GETMAT2COL;

// Check mat1col == mat2row

int mat1_len = mat1row * mat1col;
float mat1[mat1_len];
int mat2_len = mat2row * mat2col;
float mat2[mat2_len];

for(int i=0; i<mat1_len; i++) {
    int tmp = MMU.load_int32(RS1 + 4 * i);
    mat1[i] = *((float *)(&tmp));
}

for(int i=0; i<mat2_len; i++) {
    int tmp = MMU.load_int32(RS2 + 4 * i);
    mat2[i] = *((float *)(&tmp));
}


// for(int i=0; i<mat1_len; i++) {
//     fprintf(stderr, "%f, ", mat1[i]);
// }

// fprintf(stderr, "\n");

// for(int i=0; i<mat2_len; i++) {
//     fprintf(stderr, "%f, ", mat2[i]);
// }

// fprintf(stderr, "\n");

float mat3[mat1row * mat2col];
for(int i=0; i<mat1row * mat2col; i++) {
    mat3[i] = 0.0;
}

if(mat1col == mat2row) {
    for(int i=0; i<mat1row; i++) {
        for(int k=0; k<mat2col; k++) {
            for(int j=0; j<mat1col; j++) {
                // fprintf(stderr, "%d = %d x %d\n", i*mat1row+k, i*mat1col+j, j*mat2col+k);
                // fprintf(stderr, "%f += %f x %f\n", mat3[i*mat1row+k], mat1[i*mat1row+j], mat2[j*mat2row+k]);
                mat3[i*mat1row+k] += mat1[i*mat1col+j] * mat2[j*mat2col+k];
            }
        }
    }
    for(int i=0; i<mat1row * mat2col; i++) {
        int tmp = *((int *)(&mat3[i]));
        MMU.store_uint32(RD + 4 * i, tmp);
        // fprintf(stderr, "%f, ", mat3[i]);
    }
    // fprintf(stderr, "\n");


    
} else {
    fprintf(stderr, "ERROR: mat1col != mat2row\n");
}
ALL_INSN_ADD1;
