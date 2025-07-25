#include "matrix.h"

int mult_number(matrix_t *A, double number, matrix_t *result) {
  int status_matrix = check_matrices(1, A);
  if (status_matrix == OK) {
    status_matrix = create_matrix(A->rows, A->columns, result);
  }

  if (status_matrix == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return status_matrix;
}
