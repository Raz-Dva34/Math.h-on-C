#include "suitcases.h"

START_TEST(test_s21_abs_1) {
  int i = 111;
  ck_assert_int_eq(abs(i), s21_abs(i));
}
END_TEST

START_TEST(test_s21_abs_2) {
  int i = -111;
  ck_assert_int_eq(abs(i), s21_abs(i));
}
END_TEST

START_TEST(test_s21_abs_3) {
  int i = -0;
  ck_assert_int_eq(abs(i), s21_abs(i));
}
END_TEST

START_TEST(test_s21_abs_4) {
  int i = 0;
  ck_assert_int_eq(abs(i), s21_abs(i));
}
END_TEST

START_TEST(test_s21_abs_5) {
  int i = INT_MAX;
  ck_assert_int_eq(abs(i), s21_abs(i));
}
END_TEST

START_TEST(test_s21_abs_6) {
  int i = INT_MIN;
  ck_assert_int_eq(abs(i), s21_abs(i));
}
END_TEST

Suite *suite_s21_abs() {
  Suite *abs_1;
  TCase *abs_tc1;

  abs_1 = suite_create("s21_abs");
  abs_tc1 = tcase_create("case_abs");

  tcase_add_test(abs_tc1, test_s21_abs_1);
  tcase_add_test(abs_tc1, test_s21_abs_2);
  tcase_add_test(abs_tc1, test_s21_abs_3);
  tcase_add_test(abs_tc1, test_s21_abs_4);
  tcase_add_test(abs_tc1, test_s21_abs_5);
  tcase_add_test(abs_tc1, test_s21_abs_6);

  suite_add_tcase(abs_1, abs_tc1);

  return abs_1;
}
