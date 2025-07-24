#include <check.h>

#include "../matrix.h"

START_TEST(create_matrix_1) {
  matrix_t A;
  matrix_t B;

  int result = create_matrix(2, 2, &A);
  int result2 = create_matrix(10, 10, &B);
  ck_assert_int_eq(result, OK);
  ck_assert_int_eq(result2, OK);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t A;

  int result = create_matrix(3, 1, &A);
  ck_assert_int_eq(result, OK);

  int result2 = create_matrix(-1, 3, &A);
  ck_assert_int_eq(result2, INCORRECT_MATRIX);

  remove_matrix(&A);
}
END_TEST

START_TEST(remove_matrix_1) {
  matrix_t A;
  int result = create_matrix(3, 3, &A);

  remove_matrix(&A);
  remove_matrix(&A);

  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(eq_matrix_1) {
  matrix_t A;
  matrix_t B;

  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 5;
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = 5;
    }
  }

  int result1 = eq_matrix(&A, &B);
  ck_assert_int_eq(result1, SUCCESS);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A;
  matrix_t B;

  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  filling_matrix(&A, 5);
  filling_matrix(&B, 10);

  int result1 = eq_matrix(&A, &B);
  ck_assert_int_eq(result1, FAILURE);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t A;
  matrix_t B;

  create_matrix(3, 3, &A);
  create_matrix(3, 2, &B);

  filling_matrix(&A, 5);
  filling_matrix(&B, 5);

  int result1 = eq_matrix(&A, &B);
  ck_assert_int_eq(result1, FAILURE);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t A;
  matrix_t B;

  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  filling_matrix(&A, 5);
  filling_matrix(&B, 4);

  int result1 = eq_matrix(&A, &B);
  ck_assert_int_eq(result1, FAILURE);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t A;
  matrix_t B;

  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  filling_matrix(&A, 5);
  copy_matrix(&A, &B);

  int result1 = eq_matrix(&A, &B);
  ck_assert_int_eq(result1, SUCCESS);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_6) {
  matrix_t A;
  matrix_t B;

  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  filling_matrix(&A, 5);
  copy_matrix(&A, &B);

  A.matrix[0][0] = 5. / 2.;
  B.matrix[0][0] = 2.5;
  int result1 = eq_matrix(&A, &B);
  ck_assert_int_eq(result1, SUCCESS);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_7) {
  matrix_t A, B;
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.12345675;
  B.matrix[0][0] = 1.12345678;

  A.matrix[0][1] = 2.00000001;
  B.matrix[0][1] = 2.00000000;

  A.matrix[1][0] = 3.1415926;
  B.matrix[1][0] = 3.1415926;

  A.matrix[1][1] = 0.00000001;
  B.matrix[1][1] = 0.00000000;

  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_8) {
  matrix_t A, B;
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);

  A.matrix[0][0] = 0.1234567;
  B.matrix[0][0] = 0.1234568;

  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_9) {
  matrix_t A, B;
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);

  A.matrix[0][0] = 0.0000001;
  B.matrix[0][0] = 0.0000000;

  A.matrix[0][1] = -0.0000001;
  B.matrix[0][1] = 0.0000000;

  A.matrix[1][0] = 1e-7;
  B.matrix[1][0] = 0.0;

  A.matrix[1][1] = -1e-7;
  B.matrix[1][1] = 0.0;

  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_10) {
  matrix_t A, B;
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);

  A.matrix[0][0] = 1234567.1234567;
  B.matrix[0][0] = 1234567.1234568;

  A.matrix[0][1] = 9876543.2109876;
  B.matrix[0][1] = 9876543.2109877;

  A.matrix[1][0] = 5555555.5555555;
  B.matrix[1][0] = 5555555.5555556;

  A.matrix[1][1] = 1111111.1111111;
  B.matrix[1][1] = 1111111.1111112;

  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_11) {
  matrix_t A, B;
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  A.matrix[0][0] = 1.00000001;
  B.matrix[0][0] = 1.00000000;

  A.matrix[0][1] = 2.0000001;
  B.matrix[0][1] = 2.0000000;

  A.matrix[0][2] = 3.1415926;
  B.matrix[0][2] = 3.1415926;

  A.matrix[1][0] = 4.0;
  B.matrix[1][0] = 5.0;

  A.matrix[1][1] = -6.0;
  B.matrix[1][1] = 6.0;

  A.matrix[1][2] = 0.0;
  B.matrix[1][2] = 1e-8;

  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  B.matrix[2][0] = 7.0;
  B.matrix[2][1] = 8.0;
  B.matrix[2][2] = 9.0;

  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_12) {
  matrix_t A, B;
  create_matrix(1, 2, &A);
  create_matrix(1, 2, &B);

  A.matrix[0][0] = 1.0000001;
  B.matrix[0][0] = 1.0000000;

  A.matrix[0][1] = 2.00000009;
  B.matrix[0][1] = 2.00000000;

  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_13) {
  matrix_t A, B;
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);

  A.matrix[0][0] = 0.;
  B.matrix[0][0] = 0.;

  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_14) {
  matrix_t A = {0};
  matrix_t B;
  create_matrix(2, 2, &B);
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t C;

  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  filling_matrix(&A, 5);
  filling_matrix(&B, 5);

  int result = sum_matrix(&A, &B, &C);

  ck_assert_int_eq(result, OK);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&C);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};

  int result = sum_matrix(&A, &B, &C);

  ck_assert_int_eq(result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;

  create_matrix(3, 3, &A);
  create_matrix(3, 2, &B);

  filling_matrix(&A, 5);
  filling_matrix(&B, 5);

  int result = sum_matrix(&A, &B, &C);

  ck_assert_int_eq(result, CALCULATION_ERROR);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result;

  int code = sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t *A = NULL;
  matrix_t *B = NULL;
  matrix_t result;

  int code = sum_matrix(A, B, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_matrix_6) {
  matrix_t A, B, result;
  create_matrix(2, 2, &A);
  create_matrix(3, 3, &B);

  int code = sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_7) {
  matrix_t A, B, result;
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);

  A.matrix[0][0] = DBL_MAX;
  B.matrix[0][0] = DBL_MAX;

  int code = sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_8) {
  matrix_t A, B, result;
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 0.5;
  B.matrix[0][1] = 1.5;
  B.matrix[1][0] = 2.5;
  B.matrix[1][1] = 3.5;

  int code = sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 1.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 3.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 5.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 7.5, 1e-6);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t C;

  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  filling_matrix(&A, 5);
  filling_matrix(&B, 5);

  int result = sub_matrix(&A, &B, &C);

  ck_assert_int_eq(result, OK);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&C);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};

  int result = sub_matrix(&A, &B, &C);

  ck_assert_int_eq(result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;

  create_matrix(3, 3, &A);
  create_matrix(3, 4, &B);

  filling_matrix(&A, 5);
  filling_matrix(&B, 5);

  int result = sub_matrix(&A, &B, &C);

  ck_assert_int_eq(result, CALCULATION_ERROR);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result;

  int code = sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sub_matrix_5) {
  matrix_t *A = NULL;
  matrix_t *B = NULL;
  matrix_t result;

  int code = sub_matrix(A, B, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(sub_matrix_6) {
  matrix_t A, B, result;
  create_matrix(2, 2, &A);
  create_matrix(3, 3, &B);

  int code = sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_7) {
  matrix_t A, B, result;
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);

  A.matrix[0][0] = 1e-15;
  B.matrix[0][0] = 1e-16;

  int code = sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 9e-16, 1e-20);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_8) {
  matrix_t A, B, result;
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);

  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = 8.0;
  A.matrix[1][0] = 12.0;
  A.matrix[1][1] = 3.0;

  B.matrix[0][0] = 1.5;
  B.matrix[0][1] = 2.5;
  B.matrix[1][0] = 3.5;
  B.matrix[1][1] = 4.5;

  int code = sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 3.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 5.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 8.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], -1.5, 1e-6);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_9) {
  matrix_t A, B, result;
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);

  A.matrix[0][0] = DBL_MAX;
  B.matrix[0][0] = -DBL_MAX;

  int code = sub_matrix(&A, &B, &result);

  ck_assert_int_eq(code, CALCULATION_ERROR);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(sub_matrix_10) {
  matrix_t A = {0};
  matrix_t B;
  create_matrix(2, 2, &B);
  matrix_t result;
  int code = sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
  remove_matrix(&B);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t A = {};
  matrix_t B;

  create_matrix(5, 8, &A);
  filling_matrix(&A, 5.0);

  int result = transpose(&A, &B);

  ck_assert_int_eq(result, OK);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A = {};
  matrix_t B;

  create_matrix(1, 5, &A);
  filling_matrix(&A, 5.0);

  int result = transpose(&A, &B);

  ck_assert_int_eq(result, OK);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A = {};
  matrix_t B;

  create_matrix(5, 1, &A);
  filling_matrix(&A, 5.0);

  int result = transpose(&A, &B);

  ck_assert_int_eq(result, OK);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A = {};
  matrix_t B;

  int result = transpose(&A, &B);

  ck_assert_int_eq(result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t A;
  double my_dtr;
  create_matrix(4, 4, &A);

  A.matrix[0][0] = 25;
  A.matrix[0][1] = 16;
  A.matrix[0][2] = 46;
  A.matrix[0][3] = 0;
  A.matrix[1][0] = 45;
  A.matrix[1][1] = 34;
  A.matrix[1][2] = 3;
  A.matrix[1][3] = 41;
  A.matrix[2][0] = 35;
  A.matrix[2][1] = 61;
  A.matrix[2][2] = 34;
  A.matrix[2][3] = 11;
  A.matrix[3][0] = 7;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 34;
  A.matrix[3][3] = 3;

  int result = determinant(&A, &my_dtr);
  ck_assert_int_eq(result, OK);
  double rounded_result = round(my_dtr * 1e6) / 1e6;
  ck_assert_double_eq(rounded_result, 1010938);
  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A = {0};
  double detM, detRes = 73055;
  create_matrix(3, 3, &A);
  A.matrix[0][0] = 25;
  A.matrix[0][1] = 16;
  A.matrix[0][2] = 46;
  A.matrix[1][0] = 45;
  A.matrix[1][1] = 34;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 35;
  A.matrix[2][1] = 61;
  A.matrix[2][2] = 34;

  int ret = determinant(&A, &detM);
  ck_assert_int_eq(ret, OK);
  ck_assert_int_eq(detRes, detM);
  remove_matrix(&A);
}

START_TEST(determinant_3) {
  matrix_t A = {0};
  double detM, detRes = 48730;
  create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 16;
  A.matrix[0][2] = 46;
  A.matrix[1][0] = 45;
  A.matrix[1][1] = 34;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 35;
  A.matrix[2][1] = 61;
  A.matrix[2][2] = 34;

  int ret = determinant(&A, &detM);
  ck_assert_int_eq(ret, OK);
  ck_assert_int_eq(detRes, detM);
  remove_matrix(&A);
}

START_TEST(determinant_4) {
  matrix_t M_1;
  double detM, detRes = 0;
  create_matrix(3, 3, &M_1);
  M_1.matrix[0][0] = 1;
  M_1.matrix[0][1] = 2;
  M_1.matrix[0][2] = 3;
  M_1.matrix[1][0] = 4;
  M_1.matrix[1][1] = 5;
  M_1.matrix[1][2] = 6;
  M_1.matrix[2][0] = 7;
  M_1.matrix[2][1] = 8;
  M_1.matrix[2][2] = 9;
  int ret = determinant(&M_1, &detM);
  ck_assert_int_eq(ret, OK);
  ck_assert_int_eq(detRes, detM);
  remove_matrix(&M_1);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A;
  double result;

  create_matrix(1, 1, &A);

  A.matrix[0][0] = 6;

  int ret = determinant(&A, &result);
  ck_assert_int_eq(ret, OK);

  remove_matrix(&A);
}
END_TEST

START_TEST(determinant_7) {
  matrix_t A = {0};
  double result = 0;
  create_matrix(3, 0, &A);
  int ret = determinant(&A, &result);
  ck_assert_int_eq(ret, INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_1) {
  matrix_t A;
  matrix_t result;

  create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int ret = calc_complements(&A, &result);
  ck_assert_int_eq(ret, OK);

  ck_assert_double_eq(result.matrix[0][0], 4);
  ck_assert_double_eq(result.matrix[0][1], -3);
  ck_assert_double_eq(result.matrix[1][0], -2);
  ck_assert_double_eq(result.matrix[1][1], 1);

  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_5) {
  matrix_t A;
  matrix_t result;

  create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 1;

  int ret = calc_complements(&A, &result);
  ck_assert_int_eq(ret, OK);

  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[1][1], 1);
  ck_assert_double_eq(result.matrix[2][2], 1);
  ck_assert_double_eq(result.matrix[3][3], 1);

  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_matrix_3) {
  matrix_t A, B, result;
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);

  int res = mult_matrix(NULL, &B, &result);
  ck_assert_int_eq(res, 1);

  res = mult_matrix(&A, NULL, &result);
  ck_assert_int_eq(res, 1);

  res = mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(test_mult_matrix_4) {
  matrix_t A, B, result;
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);

  A.matrix[0][0] = DBL_MAX;
  B.matrix[0][0] = 2;

  int res = mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);

  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(test_mult_matrix_1) {
  matrix_t A, B, result;
  create_matrix(2, 3, &A);
  create_matrix(3, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[1][0] = 9;
  B.matrix[1][1] = 10;
  B.matrix[2][0] = 11;
  B.matrix[2][1] = 12;

  int res = mult_matrix(&A, &B, &result);

  ck_assert_int_eq(res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 58, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 64, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 139, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 154, 1e-6);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}

START_TEST(test_mult_matrix_2) {
  matrix_t A, B, result;
  create_matrix(2, 2, &A);
  create_matrix(3, 3, &B);

  int res = mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_number_1) {
  matrix_t A, result;
  create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  double number = 2.5;
  int res = mult_number(&A, number, &result);

  ck_assert_int_eq(res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 2.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 5.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 7.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 10.0, 1e-6);

  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_2) {
  matrix_t A, result;
  create_matrix(2, 2, &A);

  int res = mult_number(NULL, 2.0, &result);
  ck_assert_int_eq(res, 1);

  res = mult_number(&A, 2.0, NULL);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t A, B, result;
  create_matrix(2, 3, &A);
  create_matrix(3, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[1][0] = 9;
  B.matrix[1][1] = 10;
  B.matrix[2][0] = 11;
  B.matrix[2][1] = 12;

  int res = mult_matrix(&A, &B, &result);

  ck_assert_int_eq(res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 58, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 64, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 139, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 154, 1e-6);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}

START_TEST(mult_matrix_2) {
  matrix_t A, B, result;
  create_matrix(2, 2, &A);
  create_matrix(3, 3, &B);

  int res = mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);

  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(mult_matrix_3) {
  matrix_t A, B, result;
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);

  int res = mult_matrix(NULL, &B, &result);
  ck_assert_int_eq(res, 1);

  res = mult_matrix(&A, NULL, &result);
  ck_assert_int_eq(res, 1);

  res = mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(res, 1);

  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(mult_matrix_4) {
  matrix_t A, B, result;
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &B);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 1;
      B.matrix[i][j] = 1;
    }
  }

  int res = mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 3, 1e-6);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}

START_TEST(mult_matrix_5) {
  matrix_t A, B, result;
  create_matrix(1, 3, &A);
  create_matrix(3, 1, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  B.matrix[0][0] = 4;
  B.matrix[1][0] = 5;
  B.matrix[2][0] = 6;

  int res = mult_matrix(&A, &B, &result);

  ck_assert_int_eq(res, 0);
  ck_assert_double_eq_tol(result.matrix[0][0], 32, 1e-6);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&result);
}

START_TEST(mult_matrix_7) {
  matrix_t A, B, result;
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);

  A.matrix[0][0] = DBL_MAX;
  B.matrix[0][0] = DBL_MAX;

  int code = mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  ck_assert_ptr_eq(result.matrix, NULL);

  remove_matrix(&A);
  remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_8) {
  matrix_t *A = NULL;
  matrix_t B, result;
  create_matrix(2, 2, &B);

  int code = mult_matrix(A, &B, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);

  remove_matrix(&B);
}
END_TEST

START_TEST(inverse_matrix_1) {
  matrix_t A;
  matrix_t result;
  matrix_t expected;

  create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  int res = inverse_matrix(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(eq_matrix(&result, &expected), SUCCESS);

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&expected);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A;
  matrix_t result;

  create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int res = inverse_matrix(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);

  remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A;
  matrix_t result;
  matrix_t expected;

  create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;

  create_matrix(1, 1, &expected);
  expected.matrix[0][0] = 0.2;

  int res = inverse_matrix(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(eq_matrix(&result, &expected), SUCCESS);

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&expected);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A;
  matrix_t result;

  create_matrix(2, 3, &A);

  int res = inverse_matrix(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);

  remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A = {0};
  matrix_t result;

  int res = inverse_matrix(&A, &result);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t A;
  matrix_t result;
  matrix_t expected;

  create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  create_matrix(2, 2, &expected);
  expected.matrix[0][0] = -2;
  expected.matrix[0][1] = 1;
  expected.matrix[1][0] = 1.5;
  expected.matrix[1][1] = -0.5;

  int res = inverse_matrix(&A, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(eq_matrix(&result, &expected), SUCCESS);

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&expected);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t A;
  matrix_t result;
  matrix_t identity;

  create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  create_matrix(3, 3, &identity);
  identity.matrix[0][0] = 1;
  identity.matrix[0][1] = 0;
  identity.matrix[0][2] = 0;
  identity.matrix[1][0] = 0;
  identity.matrix[1][1] = 1;
  identity.matrix[1][2] = 0;
  identity.matrix[2][0] = 0;
  identity.matrix[2][1] = 0;
  identity.matrix[2][2] = 1;

  int res = inverse_matrix(&A, &result);
  ck_assert_int_eq(res, OK);

  matrix_t mult_result;
  mult_matrix(&A, &result, &mult_result);
  ck_assert_int_eq(eq_matrix(&mult_result, &identity), SUCCESS);

  remove_matrix(&A);
  remove_matrix(&result);
  remove_matrix(&identity);
  remove_matrix(&mult_result);
}
END_TEST

START_TEST(inverse_matrix_9) {
  matrix_t A, result;
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1e-8;
  A.matrix[1][0] = 1e-8;
  A.matrix[1][1] = 1;

  int code = inverse_matrix(&A, &result);
  ck_assert_int_eq(code, OK);
  remove_matrix(&A);
  remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_10) {
  matrix_t A, result;
  create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1 + 1e-8;
  int code = inverse_matrix(&A, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_11) {
  matrix_t A, result;
  create_matrix(2, 3, &A);
  int code = inverse_matrix(&A, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_12) {
  matrix_t A = {0};
  matrix_t result;
  int code = inverse_matrix(&A, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

Suite *matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("matrix");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, create_matrix_1);
  tcase_add_test(tc_core, create_matrix_2);
  tcase_add_test(tc_core, remove_matrix_1);
  tcase_add_test(tc_core, eq_matrix_1);
  tcase_add_test(tc_core, eq_matrix_2);
  tcase_add_test(tc_core, eq_matrix_3);
  tcase_add_test(tc_core, eq_matrix_4);
  tcase_add_test(tc_core, eq_matrix_5);
  tcase_add_test(tc_core, eq_matrix_6);
  tcase_add_test(tc_core, eq_matrix_7);
  tcase_add_test(tc_core, eq_matrix_8);
  tcase_add_test(tc_core, eq_matrix_9);
  tcase_add_test(tc_core, eq_matrix_10);
  tcase_add_test(tc_core, eq_matrix_11);
  tcase_add_test(tc_core, eq_matrix_12);
  tcase_add_test(tc_core, eq_matrix_13);
  tcase_add_test(tc_core, eq_matrix_14);
  tcase_add_test(tc_core, sum_matrix_1);
  tcase_add_test(tc_core, sum_matrix_2);
  tcase_add_test(tc_core, sum_matrix_3);
  tcase_add_test(tc_core, sum_matrix_4);
  tcase_add_test(tc_core, sum_matrix_5);
  tcase_add_test(tc_core, sum_matrix_6);
  tcase_add_test(tc_core, sum_matrix_7);
  tcase_add_test(tc_core, sum_matrix_8);
  tcase_add_test(tc_core, sub_matrix_1);
  tcase_add_test(tc_core, sub_matrix_2);
  tcase_add_test(tc_core, sub_matrix_3);
  tcase_add_test(tc_core, sub_matrix_4);
  tcase_add_test(tc_core, sub_matrix_5);
  tcase_add_test(tc_core, sub_matrix_6);
  tcase_add_test(tc_core, sub_matrix_7);
  tcase_add_test(tc_core, sub_matrix_8);
  tcase_add_test(tc_core, sub_matrix_9);
  tcase_add_test(tc_core, sub_matrix_10);
  tcase_add_test(tc_core, transpose_1);
  tcase_add_test(tc_core, transpose_2);
  tcase_add_test(tc_core, transpose_3);
  tcase_add_test(tc_core, transpose_4);
  tcase_add_test(tc_core, determinant_1);
  tcase_add_test(tc_core, determinant_2);
  tcase_add_test(tc_core, determinant_3);
  tcase_add_test(tc_core, determinant_4);
  tcase_add_test(tc_core, determinant_5);
  tcase_add_test(tc_core, determinant_7);
  tcase_add_test(tc_core, calc_complements_1);
  tcase_add_test(tc_core, calc_complements_5);
  tcase_add_test(tc_core, test_mult_matrix_1);
  tcase_add_test(tc_core, test_mult_matrix_2);
  tcase_add_test(tc_core, test_mult_matrix_3);
  tcase_add_test(tc_core, test_mult_matrix_4);

  tcase_add_test(tc_core, mult_matrix_1);
  tcase_add_test(tc_core, mult_matrix_2);
  tcase_add_test(tc_core, mult_matrix_3);
  tcase_add_test(tc_core, mult_matrix_4);
  tcase_add_test(tc_core, mult_matrix_5);

  tcase_add_test(tc_core, mult_matrix_7);
  tcase_add_test(tc_core, mult_matrix_8);
  tcase_add_test(tc_core, inverse_matrix_1);
  tcase_add_test(tc_core, inverse_matrix_2);
  tcase_add_test(tc_core, inverse_matrix_3);
  tcase_add_test(tc_core, inverse_matrix_4);
  tcase_add_test(tc_core, inverse_matrix_5);
  tcase_add_test(tc_core, inverse_matrix_6);
  tcase_add_test(tc_core, inverse_matrix_7);

  tcase_add_test(tc_core, inverse_matrix_9);
  tcase_add_test(tc_core, inverse_matrix_10);
  tcase_add_test(tc_core, inverse_matrix_11);
  tcase_add_test(tc_core, inverse_matrix_12);
  tcase_add_test(tc_core, test_mult_number_1);
  tcase_add_test(tc_core, test_mult_number_2);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  Suite *s = matrix_suite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
  return 0;
}
