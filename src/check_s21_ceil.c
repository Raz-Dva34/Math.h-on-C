#include "suitcases.h"

START_TEST(test_s21_ceil_1) {
  double d = 0;
  ck_assert_double_eq_tol(ceil(d), s21_ceil(d), 0.00001);
}
END_TEST

START_TEST(test_s21_ceil_2) {
  double d = -0;
  ck_assert_double_eq_tol(ceil(d), s21_ceil(d), 0.00001);
}
END_TEST

START_TEST(test_s21_ceil_3) {
  double d = 34;
  ck_assert_double_eq_tol(ceil(d), s21_ceil(d), 0.00001);
}
END_TEST

START_TEST(test_s21_ceil_4) {
  double d = 4.4;
  ck_assert_double_eq_tol(ceil(d), s21_ceil(d), 0.00001);
}
END_TEST

START_TEST(test_s21_ceil_5) {
  double d = -23;
  ck_assert_double_eq_tol(ceil(d), s21_ceil(d), 0.00001);
}
END_TEST

START_TEST(test_s21_ceil_6) {
  double d = -43.46;
  ck_assert_double_eq_tol(ceil(d), s21_ceil(d), 0.00001);
}
END_TEST

START_TEST(test_s21_ceil_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(ceil(d)), isnan(s21_ceil(d)));
}
END_TEST

START_TEST(test_s21_ceil_8) {
  double d = s21_INF;
  ck_assert_double_eq(ceil(d), s21_ceil(d));
}
END_TEST

START_TEST(test_s21_ceil_9) {
  double d = s21_NINF;
  ck_assert_double_eq(ceil(d), s21_ceil(d));
}
END_TEST

START_TEST(test_s21_ceil_10) {
  double d = 0.99999;
  ck_assert_double_eq_tol(ceil(d), s21_ceil(d), 0.00001);
}
END_TEST

START_TEST(test_s21_ceil_11) {
  ck_assert_double_eq(ceil(INFINITY), s21_ceil(s21_INF));
  ck_assert_double_eq(ceil(-INFINITY), s21_ceil(s21_NINF));
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(s21_ceil(s21_NAN));
  ck_assert_double_eq(ceil(-7.0), s21_ceil(-7.0));
  ck_assert_double_eq(ceil(-98.1), s21_ceil(-98.1));
  ck_assert_double_eq(ceil(123.02), s21_ceil(123.02));
  ck_assert_double_eq(ceil(10009.00123), s21_ceil(10009.00123));
  ck_assert_double_eq(ceil(-10009.555), s21_ceil(-10009.555));
  ck_assert_double_eq(ceil(-0.10009), s21_ceil(-0.10009));
  ck_assert_double_eq(ceil(-1e-23), s21_ceil(-1e-23));
}
END_TEST

Suite *suite_s21_ceil() {
  Suite *ceil_1;
  TCase *ceil_tc1;

  ceil_1 = suite_create("s21_ceil");
  ceil_tc1 = tcase_create("case_ceil");

  tcase_add_test(ceil_tc1, test_s21_ceil_1);
  tcase_add_test(ceil_tc1, test_s21_ceil_2);
  tcase_add_test(ceil_tc1, test_s21_ceil_3);
  tcase_add_test(ceil_tc1, test_s21_ceil_4);
  tcase_add_test(ceil_tc1, test_s21_ceil_5);
  tcase_add_test(ceil_tc1, test_s21_ceil_6);
  tcase_add_test(ceil_tc1, test_s21_ceil_7);
  tcase_add_test(ceil_tc1, test_s21_ceil_8);
  tcase_add_test(ceil_tc1, test_s21_ceil_9);
  tcase_add_test(ceil_tc1, test_s21_ceil_10);
  tcase_add_test(ceil_tc1, test_s21_ceil_11);

  suite_add_tcase(ceil_1, ceil_tc1);

  return ceil_1;
}