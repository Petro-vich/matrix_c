#include "matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_matrices(1, A) != OK) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  double det = 0;
  int status = determinant(A, &det);
  if (status != OK) return status;

  if (fabs(det) < 1e-7) {
    return CALCULATION_ERROR;
  }

  if (A->rows == 1) {
    create_matrix(1, 1, result);
    result->matrix[0][0] = 1.0 / det;
    return OK;
  }

  matrix_t comps;
  status = calc_complements(A, &comps);
  if (status != OK) return status;

  matrix_t adjoint;
  status = transpose(&comps, &adjoint);
  remove_matrix(&comps);
  if (status != OK) {
    remove_matrix(&adjoint);
    return status;
  }
  status = mult_number(&adjoint, 1.0 / det, result);
  remove_matrix(&adjoint);

  return status;
}