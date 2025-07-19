#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result || !A->matrix || !B->matrix) {
    return INCORRECT_MATRIX;
  }

  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  int status = s21_create_matrix(A->rows, B->columns, result);
  if (status != OK) return status;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < A->columns; k++) {
        double product = A->matrix[i][k] * B->matrix[k][j];

        if (isinf(product)) {
          s21_remove_matrix(result);
          return CALCULATION_ERROR;
        }
        result->matrix[i][j] += product;

        if (isinf(result->matrix[i][j])) {
          s21_remove_matrix(result);
          return CALCULATION_ERROR;
        }
      }
    }
  }

  return OK;
}