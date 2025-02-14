#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int MatrixCheck = OK;

  s21_create_matrix(A->rows, A->columns, result);

  if (A->rows < 1 || A->columns < 1 || result == NULL) {
    MatrixCheck = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return MatrixCheck;
}
