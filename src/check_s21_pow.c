#include <stdio.h>

#include "suitcases.h"

START_TEST(test_s21_pow_1) {
  double d = 0, y = 0;
  ck_assert_double_eq_tol(pow(d, y), s21_pow(d, y), 0.0000001);
}
END_TEST

START_TEST(test_s21_pow_2) {
  double d = -0, y = -0;
  ck_assert_double_eq_tol(pow(d, y), s21_pow(d, y), 0.0000001);
}
END_TEST

START_TEST(test_s21_pow_3) {
  double d = 0.5, y = 0.23;
  ck_assert_double_eq_tol(pow(d, y), s21_pow(d, y), 0.0000001);
}
END_TEST

START_TEST(test_s21_pow_4) {
  double d = 51.5, y = 5;
  ck_assert_double_eq_tol(pow(d, y), s21_pow(d, y), 0.000001);
}
END_TEST

START_TEST(test_s21_pow_5) {
  double d = -0.5, y = 0.34;
  ck_assert_int_eq(isnan(pow(d, y)), isnan(s21_pow(d, y)));
}
END_TEST

START_TEST(test_s21_pow_6) {
  double d = -75.5, y = -34.2;
  ck_assert_int_eq(isnan(pow(d, y)), isnan(s21_pow(d, y)));
}
END_TEST

START_TEST(test_s21_pow_7) {
  double d = s21_NAN, y = s21_NAN;
  ck_assert_int_eq(isnan(pow(d, y)), isnan(s21_pow(d, y)));
}
END_TEST

START_TEST(test_s21_pow_8) {
  double d = s21_INF, y = s21_INF;
  ck_assert_double_eq(pow(d, y), s21_pow(d, y));
}
END_TEST

START_TEST(test_s21_pow_9) {
  double d = s21_NINF, y = s21_NINF;
  ck_assert_double_eq(pow(d, y), s21_pow(d, y));
}
END_TEST

START_TEST(test_s21_pow_10) {
  double d = 1, y = s21_INF;
  ck_assert_double_eq_tol(pow(d, y), s21_pow(d, y), 0.0000001);
}
END_TEST

START_TEST(test_s21_pow_11) {
  double d = -51.5, y = 5;
  ck_assert_double_eq_tol(pow(d, y), s21_pow(d, y), 0.0000001);
}
END_TEST

START_TEST(test_s21_pow_12) {
  for (double k = -9; k <= 9; k += 1.7) {
    for (double g = -5; g < 5; g += 1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
      a = s21_pow(g, k);
      b = pow(g, k);

      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(test_s21_pow_13) {
  ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_double_eq(pow(-1, 3), s21_pow(-1, 3));
  ck_assert_double_eq(pow(-1, 4), s21_pow(-1, 4));
  ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
  ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
  ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
  ck_assert_double_eq(pow(INFINITY, 0), s21_pow(INFINITY, 0));
  ck_assert_double_eq(pow(INFINITY, -1), s21_pow(INFINITY, -1));
  ck_assert_double_eq(pow(-1, -INFINITY), s21_pow(-1, -INFINITY));
  ck_assert_double_eq(pow(0, INFINITY), s21_pow(0, INFINITY));
  ck_assert_double_nan(s21_pow(0, s21_NAN));
  ck_assert_double_eq(pow(NAN, 0), s21_pow(NAN, 0));
  ck_assert_double_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(INFINITY, INFINITY));
  ck_assert_double_eq(pow(INFINITY, -INFINITY), s21_pow(INFINITY, -INFINITY));
  ck_assert_double_eq(pow(-INFINITY, INFINITY), s21_pow(-INFINITY, INFINITY));
  ck_assert_double_eq(pow(-INFINITY, -INFINITY), s21_pow(-INFINITY, -INFINITY));
  ck_assert_double_eq(pow(1, -INFINITY), s21_pow(1, -INFINITY));
  ck_assert_double_eq(pow(1, NAN), s21_pow(1, s21_NAN));
  ck_assert_double_nan(s21_pow(-1, s21_NAN));
  ck_assert_double_nan(s21_pow(s21_NAN, INFINITY));
  ck_assert_double_nan(s21_pow(INFINITY, s21_NAN));
  ck_assert_double_nan(s21_pow(s21_NAN, -INFINITY));
  ck_assert_double_nan(s21_pow(-INFINITY, s21_NAN));
  ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, INFINITY));
  ck_assert_double_eq(pow(0.5, INFINITY), s21_pow(0.5, INFINITY));
  ck_assert_double_eq(pow(-2, INFINITY), s21_pow(-2, INFINITY));
  ck_assert_double_eq(pow(2, -INFINITY), s21_pow(2, -INFINITY));
  ck_assert_double_eq(pow(0.5, -INFINITY), s21_pow(0.5, -INFINITY));
  ck_assert_double_eq(pow(-2, -INFINITY), s21_pow(-2, -INFINITY));
}
END_TEST

Suite *suite_s21_pow() {
  Suite *pow_1;
  TCase *pow_tc1;

  pow_1 = suite_create("s21_pow");
  pow_tc1 = tcase_create("case_pow");

  tcase_add_test(pow_tc1, test_s21_pow_1);
  tcase_add_test(pow_tc1, test_s21_pow_2);
  tcase_add_test(pow_tc1, test_s21_pow_3);
  tcase_add_test(pow_tc1, test_s21_pow_4);
  tcase_add_test(pow_tc1, test_s21_pow_5);
  tcase_add_test(pow_tc1, test_s21_pow_6);
  tcase_add_test(pow_tc1, test_s21_pow_7);
  tcase_add_test(pow_tc1, test_s21_pow_8);
  tcase_add_test(pow_tc1, test_s21_pow_9);
  tcase_add_test(pow_tc1, test_s21_pow_10);
  tcase_add_test(pow_tc1, test_s21_pow_11);
  tcase_add_test(pow_tc1, test_s21_pow_12);
  tcase_add_test(pow_tc1, test_s21_pow_13);

  suite_add_tcase(pow_1, pow_tc1);

  return pow_1;
}