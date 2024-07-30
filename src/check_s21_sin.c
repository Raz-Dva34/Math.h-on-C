#include "suitcases.h"

START_TEST(test_s21_sin_1) {
  double d = 0;
  ck_assert_double_eq_tol(sin(d), s21_sin(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sin_2) {
  double d = -0;
  ck_assert_double_eq_tol(sin(d), s21_sin(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sin_3) {
  double d = 0.5;
  ck_assert_double_eq_tol(sin(d), s21_sin(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sin_5) {
  double d = -0.5;
  ck_assert_double_eq_tol(sin(d), s21_sin(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sin_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(sin(d)), isnan(s21_sin(d)));
}
END_TEST

START_TEST(test_s21_sin_8) {
  double d = s21_INF;
  ck_assert_int_eq(isnan(sin(d)), isnan(s21_sin(d)));
}
END_TEST

START_TEST(test_s21_sin_9) {
  double d = s21_NINF;
  ck_assert_int_eq(isnan(sin(d)), isnan(s21_sin(d)));
}
END_TEST

START_TEST(test_s21_sin_10) {
  double d = 0.99999;
  ck_assert_double_eq_tol(sin(d), s21_sin(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sin_11) {
  double d = 0.00001;
  ck_assert_double_eq_tol(sin(d), s21_sin(d), 0.000001);
}
END_TEST

START_TEST(test_s21_sin_13) {
  ck_assert_double_nan(s21_sin(s21_NAN));
  ck_assert_double_nan(s21_sin(s21_INF));
  ck_assert_double_nan(s21_sin(s21_NINF));
  ck_assert_double_eq_tol(sin(M_PI / 2), s21_sin(s21_PI / 2), 1e-7);
  ck_assert_double_eq_tol(sin(-M_PI / 2), s21_sin(s21_NPI / 2), 1e-7);
}
END_TEST

Suite *suite_s21_sin() {
  Suite *sin_1;
  TCase *sin_tc1;

  sin_1 = suite_create("s21_sin");
  sin_tc1 = tcase_create("case_sin");

  tcase_add_test(sin_tc1, test_s21_sin_1);
  tcase_add_test(sin_tc1, test_s21_sin_2);
  tcase_add_test(sin_tc1, test_s21_sin_3);
  tcase_add_test(sin_tc1, test_s21_sin_5);
  tcase_add_test(sin_tc1, test_s21_sin_7);
  tcase_add_test(sin_tc1, test_s21_sin_8);
  tcase_add_test(sin_tc1, test_s21_sin_9);
  tcase_add_test(sin_tc1, test_s21_sin_10);
  tcase_add_test(sin_tc1, test_s21_sin_11);
  tcase_add_test(sin_tc1, test_s21_sin_13);

  suite_add_tcase(sin_1, sin_tc1);

  return sin_1;
}