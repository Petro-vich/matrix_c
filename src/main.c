#include "s21_matrix.h"

int main(void) {

    matrix_t A;
    matrix_t B;
    matrix_t C;


    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);
    s21_create_matrix(3, 3, &C);

    s21_filling_matrix(&A, 5);
    s21_filling_matrix(&B, 5);

    printf("\n%ld\n", sizeof(&A));
    printf("\n%ld\n", sizeof(&B));

    int **matrix;
    printf("\n%ld\n", sizeof(**matrix));



    int result = s21_sum_matrix(&A, &B, &C);

}