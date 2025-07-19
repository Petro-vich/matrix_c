#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!A || !A->matrix || A->rows <= 0 || A->columns <= 0) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  int status = OK;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
    return OK;
  }

  if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    return OK;
  }

  *result = 0;
  for (int j = 0; j < A->columns; j++) {
    matrix_t minor;
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

    for (int m = 1, p = 0; m < A->rows; m++, p++) {
      for (int n = 0, q = 0; n < A->columns; n++) {
        if (n == j) continue;
        minor.matrix[p][q] = A->matrix[m][n];
        q++;
      }
    }

    double minor_det;
    s21_determinant(&minor, &minor_det);

    int sign = (j % 2 == 0) ? 1 : -1;

    *result += sign * A->matrix[0][j] * minor_det;

    s21_remove_matrix(&minor);
  }

  return status;
}