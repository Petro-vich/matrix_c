#include "s21_matrix.h"

int main(void){
    
int rows = 3;
int columns = 2;
matrix_t new_matrix;
matrix_t new_matrix2;

s21_create_matrix(rows, columns, &new_matrix);
s21_create_matrix(rows, columns, &new_matrix2);
s21_filling_matrix(&new_matrix);
s21_filling_matrix(&new_matrix2);
printf("%d", s21_eq_matrix(&new_matrix, &new_matrix2));
s21_remove_matrix(&new_matrix2);

}

