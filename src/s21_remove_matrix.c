#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A){
    
    for(int j = 0; j < A->rows; j++){
        free(A->matrix[j]);
    }
}
