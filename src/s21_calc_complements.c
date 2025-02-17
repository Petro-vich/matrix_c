#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int pivot = 0;

  s21_copy_matrix(A, result);
  printf("\n-----------------------\nCalc_compliments\n");
  s21_print_matrix(result);
  while (pivot < A->rows - 1) {
    for (int i = pivot + 1; i < A->rows; i++) {
      double factorial =
          result->matrix[i][pivot] / result->matrix[pivot][pivot];
      printf("\nЗначение1: %f / Значение 2: %f\n", result->matrix[i][pivot],
             result->matrix[pivot][pivot]);
      printf("\nFactorial: %f\n", factorial);

      for (int j = 0; j < A->columns; j++) {
        printf("%f - (%f * %f)\n", result->matrix[i][j], factorial,
               result->matrix[pivot][j]);
        result->matrix[i][j] =
            result->matrix[i][j] - (factorial * result->matrix[pivot][j]);
      }
      printf("\n");
      s21_print_matrix(result);
      printf("\n");
    }
    pivot++;
  }

  int determinant = 1;

  for (int i = 0, j = 0; i < result->rows; i++, j++) {
    determinant *= result->matrix[i][j];
  }
  printf("Детерминант: %d", determinant);

  return SUCCESS;
}