#include "s21_matrix.h"


int s21_create_matrix(int rows, int columns, matrix_t *result){
    
    result->matrix = (double **)malloc(rows * sizeof(double * ));//массив указателей на строки
    if (!result->matrix){
        free(result->matrix);
        return -1;
    }

    for (int i = 0; i < rows; i++){
        result->matrix[i] = (double *)malloc(columns * sizeof(double));//For every one columns
        if (!result->matrix[i]){
            for (int j = 0; j < i; j++){
                free(result->matrix[j]);
            }
        free(result->matrix);
        return -1;
        }
    }

    result->rows = rows;
    result->columns = columns;

    return 0;
}   

