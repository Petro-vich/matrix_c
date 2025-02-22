#include "s21_matrix.h"

int main(void) {

    matrix_t A;
    matrix_t B;

    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    s21_filling_matrix(&A, 5);
    s21_filling_matrix(&B, 5);
    
    int result1 = s21_eq_matrix(&A, &B);
    
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);

}