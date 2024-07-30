#include "suitcases.h"

START_TEST(test_s21_asin_1) {
  double d = 0;
  ck_assert_double_eq_tol(asin(d), s21_asin(d), 0.00001);
}
END_TEST

START_TEST(test_s21_asin_2) {
  double d = -0;
  ck_assert_double_eq_tol(asin(d), s21_asin(d), 0.00001);
}
END_TEST

START_TEST(test_s21_asin_3) {
  double d = 1;
  ck_assert_double_eq_tol(asin(d), s21_asin(d), 0.00001);
}
END_TEST

START_TEST(test_s21_asin_4) {
  double d = 45.3;
  ck_assert_int_eq(isnan(asin(d)), isnan(s21_asin(d)));
}
END_TEST

START_TEST(test_s21_asin_5) {
  double d = -42;
  ck_assert_int_eq(isnan(asin(d)), isnan(s21_asin(d)));
}
END_TEST

START_TEST(test_s21_asin_6) {
  double d = -42.99;
  ck_assert_int_eq(isnan(asin(d)), isnan(s21_asin(d)));
}
END_TEST

START_TEST(test_s21_asin_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(asin(d)), isnan(s21_asin(d)));
}
END_TEST

START_TEST(test_s21_asin_8) {
  double d = s21_INF;
  ck_assert_int_eq(isnan(asin(d)), isnan(s21_asin(d)));
}
END_TEST

START_TEST(test_s21_asin_9) {
  double d = s21_NINF;
  ck_assert_int_eq(isnan(asin(d)), isnan(s21_asin(d)));
}
END_TEST

START_TEST(test_s21_asin_10) {
  double d = 0.99999;
  ck_assert_double_eq_tol(asin(d), s21_asin(d), 0.00001);
}
END_TEST

START_TEST(test_s21_asin_11) {
  double d = 0.00001;
  ck_assert_double_eq_tol(asin(d), s21_asin(d), 0.00001);
}
END_TEST

START_TEST(test_s21_asin_12) {
  for (float k = -1; k <= 1; k += 0.0771) {
    double a = s21_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

Suite *suite_s21_asin() {
  Suite *asin_1;
  TCase *asin_tc1;

  asin_1 = suite_create("s21_asin");
  asin_tc1 = tcase_create("case_asin");

  tcase_add_test(asin_tc1, test_s21_asin_1);
  tcase_add_test(asin_tc1, test_s21_asin_2);
  tcase_add_test(asin_tc1, test_s21_asin_3);
  tcase_add_test(asin_tc1, test_s21_asin_4);
  tcase_add_test(asin_tc1, test_s21_asin_5);
  tcase_add_test(asin_tc1, test_s21_asin_6);
  tcase_add_test(asin_tc1, test_s21_asin_7);
  tcase_add_test(asin_tc1, test_s21_asin_8);
  tcase_add_test(asin_tc1, test_s21_asin_9);
  tcase_add_test(asin_tc1, test_s21_asin_10);
  tcase_add_test(asin_tc1, test_s21_asin_11);
  tcase_add_test(asin_tc1, test_s21_asin_12);

  suite_add_tcase(asin_1, asin_tc1);

  return asin_1;
}