#include "suitcases.h"

START_TEST(test_s21_floor_1) {
  double d = 0;
  ck_assert_double_eq_tol(floor(d), s21_floor(d), 0.000001);
}
END_TEST

START_TEST(test_s21_floor_2) {
  double d = -0;
  ck_assert_double_eq_tol(floor(d), s21_floor(d), 0.000001);
}
END_TEST

START_TEST(test_s21_floor_3) {
  double d = 0.5;
  ck_assert_double_eq_tol(floor(d), s21_floor(d), 0.000001);
}
END_TEST

START_TEST(test_s21_floor_4) {
  double d = 51.5;
  ck_assert_double_eq_tol(floor(d), s21_floor(d), 0.000001);
}
END_TEST

START_TEST(test_s21_floor_5) {
  double d = -0.5;
  ck_assert_double_eq_tol(floor(d), s21_floor(d), 0.000001);
}
END_TEST

START_TEST(test_s21_floor_6) {
  double d = -75.5;
  ck_assert_double_eq_tol(floor(d), s21_floor(d), 0.000001);
}
END_TEST

START_TEST(test_s21_floor_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(floor(d)), isnan(s21_floor(d)));
}
END_TEST

START_TEST(test_s21_floor_8) {
  double d = s21_INF;
  ck_assert_double_eq(floor(d), s21_floor(d));
}
END_TEST

START_TEST(test_s21_floor_9) {
  double d = s21_NINF;
  ck_assert_double_eq(floor(d), s21_floor(d));
}
END_TEST

START_TEST(test_s21_floor_10) {
  double d = 23.3;
  ck_assert_double_eq_tol(floor(d), s21_floor(d), 0.000001);
}
END_TEST

START_TEST(test_s21_floor_11) {
  ck_assert_double_eq(floor(INFINITY), s21_floor(s21_INF));
  ck_assert_double_eq(floor(-INFINITY), s21_floor(s21_NINF));
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_nan(s21_floor(s21_NAN));
  ck_assert_double_eq(floor(-7.0), s21_floor(-7.0));
  ck_assert_double_eq(floor(-98.1), s21_floor(-98.1));
  ck_assert_double_eq(floor(123.02), s21_floor(123.02));
  ck_assert_double_eq(floor(10009.00123), s21_floor(10009.00123));
  ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
  ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
  ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23));
  ck_assert_double_eq(floor(100091234.5), s21_floor(100091234.5));
}
END_TEST

Suite *suite_s21_floor() {
  Suite *floor_1;
  TCase *floor_tc1;

  floor_1 = suite_create("s21_floor");
  floor_tc1 = tcase_create("case_floor");

  tcase_add_test(floor_tc1, test_s21_floor_1);
  tcase_add_test(floor_tc1, test_s21_floor_2);
  tcase_add_test(floor_tc1, test_s21_floor_3);
  tcase_add_test(floor_tc1, test_s21_floor_4);
  tcase_add_test(floor_tc1, test_s21_floor_5);
  tcase_add_test(floor_tc1, test_s21_floor_6);
  tcase_add_test(floor_tc1, test_s21_floor_7);
  tcase_add_test(floor_tc1, test_s21_floor_8);
  tcase_add_test(floor_tc1, test_s21_floor_9);
  tcase_add_test(floor_tc1, test_s21_floor_10);
  tcase_add_test(floor_tc1, test_s21_floor_11);

  suite_add_tcase(floor_1, floor_tc1);

  return floor_1;
}