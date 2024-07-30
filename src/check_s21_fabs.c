#include "suitcases.h"

START_TEST(test_s21_fabs_1) {
  double d = 0;
  ck_assert_double_eq_tol(fabs(d), s21_fabs(d), 0.00001);
}
END_TEST

START_TEST(test_s21_fabs_2) {
  double d = -0;
  ck_assert_double_eq_tol(fabs(d), s21_fabs(d), 0.00001);
}
END_TEST

START_TEST(test_s21_fabs_3) {
  double d = 0.5;
  ck_assert_double_eq_tol(fabs(d), s21_fabs(d), 0.00001);
}
END_TEST

START_TEST(test_s21_fabs_4) {
  double d = 51.5;
  ck_assert_double_eq_tol(fabs(d), s21_fabs(d), 0.00001);
}
END_TEST

START_TEST(test_s21_fabs_5) {
  double d = -0.5;
  ck_assert_double_eq_tol(fabs(d), s21_fabs(d), 0.00001);
}
END_TEST

START_TEST(test_s21_fabs_6) {
  double d = -75.5;
  ck_assert_double_eq_tol(fabs(d), s21_fabs(d), 0.00001);
}
END_TEST

START_TEST(test_s21_fabs_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(fabs(d)), isnan(s21_fabs(d)));
}
END_TEST

START_TEST(test_s21_fabs_8) {
  double d = s21_INF;
  ck_assert_double_eq(fabs(d), s21_fabs(d));
}
END_TEST

START_TEST(test_s21_fabs_9) {
  double d = s21_NINF;
  ck_assert_double_eq(fabs(d), s21_fabs(d));
}
END_TEST

START_TEST(test_s21_fabs_10) {
  ck_assert_double_eq(fabs(INFINITY), s21_fabs(s21_INF));
  ck_assert_double_eq(fabs(-INFINITY), s21_fabs(s21_NINF));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_nan(s21_fabs(s21_NAN));
  ck_assert_double_eq(fabs(-7.0), s21_fabs(-7.0));
  ck_assert_double_eq(fabs(-98.1), s21_fabs(-98.1));
  ck_assert_double_eq(fabs(123.02), s21_fabs(123.02));
  ck_assert_double_eq(fabs(10009.0), s21_fabs(10009.0));
  ck_assert_double_eq(fabs(-10009.555), s21_fabs(-10009.555));
  ck_assert_double_eq(fabs(-0.10009), s21_fabs(-0.10009));
  ck_assert_double_eq(fabs(-1e23), s21_fabs(-1e23));
}
END_TEST

Suite *suite_s21_fabs() {
  Suite *fabs_1;
  TCase *fabs_tc1;

  fabs_1 = suite_create("s21_fabs");
  fabs_tc1 = tcase_create("case_fabs");

  tcase_add_test(fabs_tc1, test_s21_fabs_1);
  tcase_add_test(fabs_tc1, test_s21_fabs_2);
  tcase_add_test(fabs_tc1, test_s21_fabs_3);
  tcase_add_test(fabs_tc1, test_s21_fabs_4);
  tcase_add_test(fabs_tc1, test_s21_fabs_5);
  tcase_add_test(fabs_tc1, test_s21_fabs_6);
  tcase_add_test(fabs_tc1, test_s21_fabs_7);
  tcase_add_test(fabs_tc1, test_s21_fabs_8);
  tcase_add_test(fabs_tc1, test_s21_fabs_9);
  tcase_add_test(fabs_tc1, test_s21_fabs_10);

  suite_add_tcase(fabs_1, fabs_tc1);

  return fabs_1;
}