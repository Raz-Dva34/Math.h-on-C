#include "suitcases.h"

START_TEST(test_s21_tan_1) {
  double d = 0;
  ck_assert_double_eq_tol(tan(d), s21_tan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_tan_2) {
  double d = -0;
  ck_assert_double_eq_tol(tan(d), s21_tan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_tan_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(tan(d)), isnan(s21_tan(d)));
}
END_TEST

START_TEST(test_s21_tan_8) {
  double d = s21_INF;
  ck_assert_int_eq(isnan(tan(d)), isnan(s21_tan(d)));
}
END_TEST

START_TEST(test_s21_tan_9) {
  double d = s21_NINF;
  ck_assert_int_eq(isnan(tan(d)), isnan(s21_tan(d)));
}
END_TEST

START_TEST(test_s21_tan_10) {
  double d = 0.00001;
  ck_assert_double_eq(isnan(tan(d)), isnan(s21_tan(d)));
}
END_TEST

START_TEST(test_s21_tan_11) {
  double d = 0.99999;
  ck_assert_double_eq(isnan(tan(d)), isnan(s21_tan(d)));
}
END_TEST

Suite *suite_s21_tan() {
  Suite *tan_1;
  TCase *tan_tc1;

  tan_1 = suite_create("s21_tan");
  tan_tc1 = tcase_create("case_tan");

  tcase_add_test(tan_tc1, test_s21_tan_1);
  tcase_add_test(tan_tc1, test_s21_tan_2);
  tcase_add_test(tan_tc1, test_s21_tan_7);
  tcase_add_test(tan_tc1, test_s21_tan_8);
  tcase_add_test(tan_tc1, test_s21_tan_9);
  tcase_add_test(tan_tc1, test_s21_tan_10);
  tcase_add_test(tan_tc1, test_s21_tan_11);

  suite_add_tcase(tan_1, tan_tc1);

  return tan_1;
}
