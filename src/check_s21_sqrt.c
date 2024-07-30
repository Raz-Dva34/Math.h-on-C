#include "suitcases.h"

START_TEST(test_s21_sqrt_1) {
  double d = 0;
  ck_assert_double_eq_tol(sqrt(d), s21_sqrt(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sqrt_2) {
  double d = -0;
  ck_assert_double_eq_tol(sqrt(d), s21_sqrt(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sqrt_3) {
  double d = 0.5;
  ck_assert_double_eq_tol(sqrt(d), s21_sqrt(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sqrt_4) {
  double d = 51.5;
  ck_assert_double_eq_tol(sqrt(d), s21_sqrt(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sqrt_5) {
  double d = -0.5;
  ck_assert_int_eq(isnan(sqrt(d)), isnan(s21_sqrt(d)));
}
END_TEST

START_TEST(test_s21_sqrt_6) {
  double d = -75.5;
  ck_assert_int_eq(isnan(sqrt(d)), isnan(s21_sqrt(d)));
}
END_TEST

START_TEST(test_s21_sqrt_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(sqrt(d)), isnan(s21_sqrt(d)));
}
END_TEST

START_TEST(test_s21_sqrt_8) {
  double d = s21_INF;
  ck_assert_double_eq(sqrt(d), s21_sqrt(d));
}
END_TEST

START_TEST(test_s21_sqrt_9) {
  double d = s21_NINF;
  ck_assert_int_eq(isnan(sqrt(d)), isnan(s21_sqrt(d)));
}
END_TEST

START_TEST(test_s21_sqrt_10) {
  for (double k = 0; k < 21; k += 3) {
    double a = s21_sqrt(k);
    double b = sqrt(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(test_s21_sqrt_11) {
  ck_assert_double_nan(s21_sqrt(s21_NAN));
  ck_assert_double_nan(sqrt(NAN));
  ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
  ck_assert_double_nan(s21_sqrt(-INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
  ck_assert_double_nan(s21_sqrt(-5));
  ck_assert_double_nan(sqrt(-5));
  ck_assert_double_eq_tol(s21_sqrt(1000), sqrt(1000), 1e-7);
}
END_TEST

Suite *suite_s21_sqrt() {
  Suite *sqrt_1;
  TCase *sqrt_tc1;

  sqrt_1 = suite_create("s21_sqrt");
  sqrt_tc1 = tcase_create("case_sqrt");

  tcase_add_test(sqrt_tc1, test_s21_sqrt_1);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_2);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_3);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_4);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_5);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_6);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_7);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_8);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_9);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_10);
  tcase_add_test(sqrt_tc1, test_s21_sqrt_11);

  suite_add_tcase(sqrt_1, sqrt_tc1);

  return sqrt_1;
}
