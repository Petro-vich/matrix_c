#include "s21_matrix.h"

void s21_filling_matrix(matrix_t *new_matrix) {
  double count;
  for (int i = 0; i < new_matrix->rows; i++) {
    for (int j = 0; j < new_matrix->columns; j++) {
      count = rand() % 100;
      new_matrix->matrix[i][j] = count;
      count += 1.0;
    }
  }
}