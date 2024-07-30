#include "suitcases.h"

START_TEST(test_s21_log_1) {
  double d = 0;
  ck_assert_int_eq(isnan(log(d)), isnan(s21_log(d)));
}
END_TEST

START_TEST(test_s21_log_2) {
  double d = -0;
  ck_assert_int_eq(isnan(log(d)), isnan(s21_log(d)));
}
END_TEST

START_TEST(test_s21_log_3) {
  double d = 0.5;
  ck_assert_double_eq_tol(log(d), s21_log(d), 0.000001);
}
END_TEST

START_TEST(test_s21_log_4) {
  double d = 51.5;
  ck_assert_double_eq_tol(log(d), s21_log(d), 0.000001);
}
END_TEST

START_TEST(test_s21_log_5) {
  double d = -s21_NAN;
  ck_assert_int_eq(isnan(log(d)), isnan(s21_log(d)));
}
END_TEST

START_TEST(test_s21_log_6) {
  double d = -75.5;
  ck_assert_int_eq(isnan(log(d)), isnan(s21_log(d)));
}
END_TEST

START_TEST(test_s21_log_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(log(d)), isnan(s21_log(d)));
}
END_TEST

START_TEST(test_s21_log_8) {
  double d = s21_INF;
  ck_assert_double_eq(log(d), s21_log(d));
}
END_TEST

START_TEST(test_s21_log_9) {
  double d = s21_NINF;
  ck_assert_int_eq(isnan(log(d)), isnan(s21_log(d)));
}
END_TEST

START_TEST(test_s21_log_10) {
  for (double k = 1; k < 100; k += 13.2) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(test_s21_log_11) {
  for (double k = 0.1; k < 4; k += 0.24) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(test_s21_log_12) {
  for (double k = 0.1; k < 10000; k += 123) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(test_s21_log_13) {
  for (double k = 0.000005; k < 1; k *= 5) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(test_s21_log_14) {
  ck_assert_double_nan(s21_log(s21_NAN));
  ck_assert_double_eq(log(0), s21_log(0));
  ck_assert_double_nan(s21_log(-3));
  ck_assert_double_eq(log(INFINITY), s21_log(INFINITY));
  ck_assert_double_nan(s21_log(-INFINITY));
  ck_assert_double_eq(log(1), s21_log(1));
  ck_assert_double_eq(log(M_E), s21_log(M_E));
  ck_assert_double_eq_tol(log(2), s21_log(2), 1e-6);
}
END_TEST

Suite *suite_s21_log() {
  Suite *log_1;
  TCase *log_tc1;

  log_1 = suite_create("s21_log");
  log_tc1 = tcase_create("case_log");

  tcase_add_test(log_tc1, test_s21_log_1);
  tcase_add_test(log_tc1, test_s21_log_2);
  tcase_add_test(log_tc1, test_s21_log_3);
  tcase_add_test(log_tc1, test_s21_log_4);
  tcase_add_test(log_tc1, test_s21_log_5);
  tcase_add_test(log_tc1, test_s21_log_6);
  tcase_add_test(log_tc1, test_s21_log_7);
  tcase_add_test(log_tc1, test_s21_log_8);
  tcase_add_test(log_tc1, test_s21_log_9);
  tcase_add_test(log_tc1, test_s21_log_10);
  tcase_add_test(log_tc1, test_s21_log_11);
  tcase_add_test(log_tc1, test_s21_log_12);
  tcase_add_test(log_tc1, test_s21_log_13);
  tcase_add_test(log_tc1, test_s21_log_14);

  suite_add_tcase(log_1, log_tc1);

  return log_1;
}
