#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status_matrix = s21_check_matrices(2, A, B);

  if (status_matrix == OK) {
    status_matrix = s21_create_matrix(A->rows, A->columns, result);
  }

  if (status_matrix == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double diff = A->matrix[i][j] - B->matrix[i][j];

        if (isinf(diff)) {
          s21_remove_matrix(result);
          status_matrix = CALCULATION_ERROR;
          break;
        }
        result->matrix[i][j] = diff;
      }
      if (status_matrix != OK) break;
    }
  }

  return status_matrix;
}