#include "s21_matrix.h"

int s21_check_pivot(matrix_t *tmp, int *index_pivot) {
  printf("\nbefore: s21_check pivot\n");
  s21_print_matrix(tmp);

  int row_pivot = *index_pivot;
  // index_pivot - upper
  // row pivot - inder

  int swap_count = 0;

  while (tmp->matrix[row_pivot][*index_pivot] == 0 &&
         row_pivot < tmp->rows - 1) {
    row_pivot++;
  }
  if (row_pivot != *index_pivot) {
    for (int j = 0; j < tmp->columns; j++) {
      double temp = tmp->matrix[*index_pivot][j];  // up
      tmp->matrix[*index_pivot][j] = tmp->matrix[row_pivot][j];
      tmp->matrix[row_pivot][j] = temp;
    }
    swap_count = 1;
  }

  printf("\nafter: s21_check pivot\n");
  s21_print_matrix(tmp);
  return swap_count;
}

int s21_zero_out(matrix_t *tmp, matrix_t *A, int *index_pivot) {
  int swap_sign = 1;

  while (*index_pivot < A->rows - 1) {
    swap_sign *= s21_check_pivot(tmp, index_pivot) ? -1 : 1;
    if (tmp->matrix[*index_pivot][*index_pivot] == 0) {
      return 0;
    }

    for (int i = *index_pivot + 1; i < A->rows; i++) {
      double factorial = tmp->matrix[i][*index_pivot] /
                         tmp->matrix[*index_pivot][*index_pivot];
      // printf("\nЗначение1: %f / Значение 2: %f\n",
      // tmp->matrix[i][*index_pivot], tmp->matrix[*index_pivot][*index_pivot]);
      // printf("\nFactorial: %f\n", factorial);
      for (int j = 0; j < A->columns; j++) {
        // printf("\n%f - (%f * %f)\n", tmp->matrix[i][j], factorial,
        // tmp->matrix[*index_pivot][j]);
        tmp->matrix[i][j] =
            tmp->matrix[i][j] - (factorial * tmp->matrix[*index_pivot][j]);
      }
      s21_print_matrix(tmp);
    }

    *index_pivot = *index_pivot + 1;
  }
  return swap_sign;
}

int s21_determinant(matrix_t *A, double *result) {
  int status_matrix = s21_check_matrices(1, A);
  matrix_t tmp = {};
  s21_create_matrix(A->rows, A->columns, &tmp);
  s21_copy_matrix(A, &tmp);

  int index_pivot = 0;

  // printf("\n");
  // s21_print_matrix(&tmp);
  // printf("\n");

  int swap_sign = s21_zero_out(&tmp, A, &index_pivot);

  *result = tmp.matrix[0][0];

  for (int i = 1, j = 1; i < tmp.rows; i++, j++) {
    *result *= tmp.matrix[i][j];
  }

  *result *= swap_sign;
  // printf("\nДетерминант: %f\n", *result);
  s21_remove_matrix(&tmp);

  return OK;
}