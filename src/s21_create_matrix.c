#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int MatrixCheck = OK;

  if (rows <= 1 || columns <= 1 || result == NULL) {
    MatrixCheck = INCORRECT_MATRIX;
  } else {
    result->matrix = (double **)malloc(rows * sizeof(double *));  // массив указателей на строки
    if (!result->matrix) {
      MatrixCheck = INCORRECT_MATRIX;
    }
    for (int i = 0; MatrixCheck == OK && i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));  // For every one columns
      if (!result->matrix[i]) {
        MatrixCheck = INCORRECT_MATRIX;
        for (int j = 0; j < i; j++) {
          free(result->matrix[j]);
        }
        free(result->matrix); 
        break;
      }
      result->rows = rows;
      result->columns = columns;
    }
  }
  return MatrixCheck;
}
