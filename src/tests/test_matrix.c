#include <check.h>
#include "../s21_matrix.h"

START_TEST(create_matrix_1){

    matrix_t A;
    matrix_t B;

    int result = s21_create_matrix(2, 2, &A);
    int result2 = s21_create_matrix(10,10, &B);
    ck_assert_int_eq(result, OK);
    ck_assert_int_eq(result2, OK);

    s21_remove_matrix(&A); 
    s21_remove_matrix(&B); 

}   
END_TEST

START_TEST(create_matrix_2){

    matrix_t A;
    
    int result = s21_create_matrix(1, 1, &A);
    ck_assert_int_eq(result, INCORRECT_MATRIX);
    
    int result2 = s21_create_matrix(-1, 3, &A);
    ck_assert_int_eq(result2, INCORRECT_MATRIX);

    int result3 = s21_create_matrix(3, 3, NULL);
    ck_assert_int_eq(result3, INCORRECT_MATRIX);

}   
END_TEST

START_TEST(remove_matrix_1){
    
    matrix_t A;
    int result = s21_create_matrix(3,3, &A);

    s21_remove_matrix(&A);
    s21_remove_matrix(&A);
    
    ck_assert_ptr_eq(A.matrix, NULL);

    //add tests for rows -1
}
END_TEST

START_TEST(eq_matrix_1){
    matrix_t A;
    matrix_t B;

    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    s21_filling_matrix(&A, 5);
    s21_filling_matrix(&B, 5);
    
    int result1 = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result1, SUCCESS);
    
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);

}
END_TEST

END_TEST

START_TEST(eq_matrix_2){
    
    matrix_t A;
    matrix_t B;

    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    s21_filling_matrix(&A, 5);
    s21_filling_matrix(&B, 10);
    
    int result1 = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result1, FAILURE); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3){
    
    matrix_t A;
    matrix_t B;

    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 2, &B);

    s21_filling_matrix(&A, 5);
    s21_filling_matrix(&B, 5);
    
    int result1 = s21_eq_matrix(&A, &B);
    ck_assert_int_eq(result1, FAILURE); 

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

    Suite *matrix_suite(void){
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_matrix");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, create_matrix_1);
    tcase_add_test(tc_core, create_matrix_2);
    tcase_add_test(tc_core, remove_matrix_1);
    tcase_add_test(tc_core, eq_matrix_1);
    tcase_add_test(tc_core, eq_matrix_2);
    tcase_add_test(tc_core, eq_matrix_3);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void){
    Suite *s = matrix_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
    return 0;
}
