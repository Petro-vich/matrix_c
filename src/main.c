#include "s21_matrix.h"

int main(void) {
  int rows = 3;
  int columns = 3;
  // matrix_t new_matrix;
  matrix_t new_matrix1;
  matrix_t new_matrix2;
  matrix_t new_matrix3;

  s21_create_matrix(rows, columns, &new_matrix1);
  s21_create_matrix(rows, columns, &new_matrix2);
  s21_filling_matrix(&new_matrix1, 5);
  s21_filling_matrix(&new_matrix2, 10);

  int result = s21_sum_matrix(&new_matrix1, &new_matrix2, &new_matrix3);
  printf("\n%d\n", result);

  s21_remove_matrix(&new_matrix1);
  s21_remove_matrix(&new_matrix2);
  s21_remove_matrix(&new_matrix3);
}