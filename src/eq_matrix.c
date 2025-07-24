#include "matrix.h"

int eq_matrix(matrix_t *A, matrix_t *B) {
  if (check_matrices(2, A, B) != OK) return FAILURE;

  int status = SUCCESS;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
        status = FAILURE;
        break;
      }
    }
  }
  return status;
}