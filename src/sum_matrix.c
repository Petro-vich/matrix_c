#include "matrix.h"

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status_matrix = check_matrices(2, A, B);

  if (status_matrix == OK) {
    status_matrix = create_matrix(A->rows, A->columns, result);
  }

  if (status_matrix == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double sum = A->matrix[i][j] + B->matrix[i][j];

        if (isinf(sum)) {
          remove_matrix(result);
          status_matrix = CALCULATION_ERROR;
          break;
        }
        result->matrix[i][j] = sum;
      }
    }
  }

  return status_matrix;
}