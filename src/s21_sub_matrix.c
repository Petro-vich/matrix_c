#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int check_matrix = OK;

  if (!A || !B || !result || !A->matrix || !B->matrix || !result->matrix){ 
    check_matrix = INCORRECT_MATRIX;
  }
  else if (A->rows != B->rows || A->columns != B->columns ||
B->rows != result->rows || B->rows != result->columns) {
    check_matrix = CALCULATION_ERROR;
  } 
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

    return check_matrix;
}
// make function s21_check ipnut