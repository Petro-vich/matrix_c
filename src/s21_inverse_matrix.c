#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_check_matrices(1, A) != OK) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  double det = 0;
  int status = s21_determinant(A, &det);
  if (status != OK) return status;

  if (fabs(det) < 1e-7) {
    return CALCULATION_ERROR;
  }

  if (A->rows == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1.0 / det;
    return OK;
  }

  matrix_t comps;
  status = s21_calc_complements(A, &comps);
  if (status != OK) return status;

  matrix_t adjoint;
  status = s21_transpose(&comps, &adjoint);
  s21_remove_matrix(&comps);
  if (status != OK) {
    s21_remove_matrix(&adjoint);
    return status;
  }
  status = s21_mult_number(&adjoint, 1.0 / det, result);
  s21_remove_matrix(&adjoint);

  return status;
}