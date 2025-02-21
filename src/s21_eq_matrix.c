#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int check_matrix = 1;  // xz
  if (A->rows != B->rows ||
      A->columns != B->columns) {  // checking for A.matrix
    check_matrix = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] != B->matrix[i][j]) {
          check_matrix = FAILURE;
          break;
        }
      }
    }
  }
  return check_matrix;
}