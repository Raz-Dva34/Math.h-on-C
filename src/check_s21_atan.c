#include "suitcases.h"

START_TEST(test_s21_atan_1) {
  double d = 0;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_2) {
  double d = -0;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_3) {
  double d = 23;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_4) {
  double d = 2532.3;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_5) {
  double d = -345;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_6) {
  double d = -345.4;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(atan(d)), isnan(s21_atan(d)));
}
END_TEST

START_TEST(test_s21_atan_8) {
  double d = s21_INF;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_9) {
  double d = s21_NINF;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_10) {
  double d = 0.999999;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.0000001);
}
END_TEST

START_TEST(test_s21_atan_11) {
  double d = 0.00001;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_12) {
  double d = 1.99999;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_13) {
  for (float k = -10; k <= 10; k += 4) {
    double a = s21_atan(k);
    double b = atan(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(test_s21_atan_14) {
  double d = 0.9999999;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 1e-7);
}
END_TEST

START_TEST(test_s21_atan_15) {
  double d = -0.9999999;
  ck_assert_double_eq_tol(atan(d), s21_atan(d), 1e-7);
}
END_TEST

Suite *suite_s21_atan() {
  Suite *atan_1;
  TCase *atan_tc1;

  atan_1 = suite_create("s21_atan");
  atan_tc1 = tcase_create("case_atan");

  tcase_add_test(atan_tc1, test_s21_atan_1);
  tcase_add_test(atan_tc1, test_s21_atan_2);
  tcase_add_test(atan_tc1, test_s21_atan_3);
  tcase_add_test(atan_tc1, test_s21_atan_4);
  tcase_add_test(atan_tc1, test_s21_atan_5);
  tcase_add_test(atan_tc1, test_s21_atan_6);
  tcase_add_test(atan_tc1, test_s21_atan_7);
  tcase_add_test(atan_tc1, test_s21_atan_8);
  tcase_add_test(atan_tc1, test_s21_atan_9);
  tcase_add_test(atan_tc1, test_s21_atan_10);
  tcase_add_test(atan_tc1, test_s21_atan_11);
  tcase_add_test(atan_tc1, test_s21_atan_12);
  tcase_add_test(atan_tc1, test_s21_atan_13);
  tcase_add_test(atan_tc1, test_s21_atan_14);
  tcase_add_test(atan_tc1, test_s21_atan_15);

  suite_add_tcase(atan_1, atan_tc1);

  return atan_1;
}