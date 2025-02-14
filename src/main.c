#include "s21_matrix.h"

int main(void){
    
int rows = 3;
int columns = 2;
matrix_t new_matrix;
matrix_t new_matrix2;
matrix_t sum_2matrix;
matrix_t mult_matrix;
matrix_t transpose_matrix;
s21_create_matrix(rows, columns, &new_matrix);
s21_create_matrix(rows, columns, &new_matrix2);
puts("Matrix№1");
s21_filling_matrix(&new_matrix);
puts("Matrix№2");
s21_filling_matrix(&new_matrix2);

s21_sum_matrix(&new_matrix, &new_matrix2, &sum_2matrix);
printf("Сумма матриц:\n");
s21_print_matrix(&sum_2matrix);


printf("Результат сравнения: %d\n", s21_eq_matrix(&new_matrix, &new_matrix2));

double number = 29;
s21_mult_number(&new_matrix2, number, &mult_matrix);
puts("\nmult_matrix:");
s21_print_matrix(&mult_matrix);

s21_transpose(&new_matrix2, &transpose_matrix);
puts("\nransponse_matrix: ");
s21_print_matrix(&transpose_matrix);
}

    