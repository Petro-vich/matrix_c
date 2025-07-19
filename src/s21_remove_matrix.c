#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int j = 0; j < A->rows; j++) {
        free(A->matrix[j]);
      }
      free(A->matrix);
      A->matrix = NULL;
    }
    A->columns = 0;
    A->rows = 0;
  }
}