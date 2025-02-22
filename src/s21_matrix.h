#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define SUCCESS 1
#define FAILURE 0

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

enum ERROR_CODES { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

void s21_print_matrix(matrix_t *A);
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
// aux_fnc
void s21_copy_matrix(matrix_t *A, matrix_t *result);
void s21_filling_matrix(matrix_t *new_matrix, double number);
int s21_memcmp(const void *str1, const void *str2, int n);
int s21_check_matrices(int count, ...);
#endif