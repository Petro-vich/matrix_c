#ifndef AUX_FUNC_H
#define AUX_FUNC_H

void print_matrix(matrix_t *A);
void copy_matrix(matrix_t *A, matrix_t *result);
void filling_matrix(matrix_t *new_matrix, double number);
int check_matrices(int count, ...);

#endif