#include <check.h>
#include "../s21_matrix.h"

START_TEST(create_matrix_1){

    matrix_t A;

    int result = s21_create_matrix(2, 2, &A);
    ck_assert_int_eq(result, OK);

    s21_remove_matrix(&A); 
    
}   
END_TEST

START_TEST(create_matrix_2){

    matrix_t A;

    int result = s21_create_matrix(1, 1, &A);
    ck_assert_int_eq(result, INCORRECT_MATRIX);
    
}   
END_TEST

START_TEST(create_matrix_3){

    matrix_t A;

    int result = s21_create_matrix(-1, 3, &A);
    ck_assert_int_eq(result, INCORRECT_MATRIX);
    
}   
END_TEST

START_TEST(create_matrix_4){

    matrix_t A;

    int result = s21_create_matrix(3, 3, NULL);
    ck_assert_int_eq(result, INCORRECT_MATRIX);
    
}   
END_TEST

    Suite *matrix_suite(void){
    Suite *s;
    TCase *tc_core;

    s = suite_create("s21_matrix");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, create_matrix_1);
    tcase_add_test(tc_core, create_matrix_2);
    tcase_add_test(tc_core, create_matrix_3);
    tcase_add_test(tc_core, create_matrix_4);
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
