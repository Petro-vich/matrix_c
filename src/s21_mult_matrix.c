#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++){
        for (int j = 0; j < B->columns; j++){
            result->matrix[i][j] = A->matrix[i][j] * B->matrix[i][j];
        }
    }
    return SUCCESS;
}