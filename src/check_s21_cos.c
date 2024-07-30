#include "suitcases.h"

START_TEST(test_s21_cos_1) {
  double d = 0;
  ck_assert_double_eq_tol(cos(d), s21_cos(d), 0.00001);
}
END_TEST

START_TEST(test_s21_cos_2) {
  double d = -0;
  ck_assert_double_eq_tol(cos(d), s21_cos(d), 0.00001);
}
END_TEST

START_TEST(test_s21_cos_3) {
  double d = 0.5;
  ck_assert_double_eq_tol(cos(d), s21_cos(d), 0.00001);
}
END_TEST

START_TEST(test_s21_cos_4) {
  double d = 51.5;
  ck_assert_double_eq_tol(cos(d), s21_cos(d), 0.00001);
}
END_TEST

START_TEST(test_s21_cos_5) {
  double d = -0.5;
  ck_assert_double_eq_tol(cos(d), s21_cos(d), 0.00001);
}
END_TEST

START_TEST(test_s21_cos_6) {
  double d = -75.5;
  ck_assert_double_eq_tol(cos(d), s21_cos(d), 0.00001);
}
END_TEST

START_TEST(test_s21_cos_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(cos(d)), isnan(s21_cos(d)));
}
END_TEST

START_TEST(test_s21_cos_8) {
  double d = s21_INF;
  ck_assert_int_eq(isnan(cos(d)), isnan(s21_cos(d)));
}
END_TEST

START_TEST(test_s21_cos_9) {
  double d = s21_NINF;
  ck_assert_int_eq(isnan(cos(d)), isnan(s21_cos(d)));
}
END_TEST

START_TEST(test_s21_cos_10) {
  double d = 0.00001;
  ck_assert_double_eq_tol(cos(d), s21_cos(d), 0.00001);
}
END_TEST

START_TEST(test_s21_cos_11) {
  double d = 0.999999;
  ck_assert_double_eq_tol(cos(d), s21_cos(d), 1e-7);
}
END_TEST

START_TEST(test_s21_cos_12) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
      ck_assert_double_eq_tol(cos(k + R * s21_PI), s21_cos(k + R * s21_PI),
                              1e-7);
    }
  }
}
END_TEST

START_TEST(test_s21_cos_13) {
  ck_assert_double_eq_tol(cos(M_PI_2), s21_cos(M_PI_2), 1e-7);
  ck_assert_double_eq_tol(cos(-M_PI_2), s21_cos(-M_PI_2), 1e-7);
}
END_TEST

START_TEST(test_s21_cos_14) {
  ck_assert_double_nan(s21_cos(s21_NAN));
  ck_assert_double_nan(s21_cos(INFINITY));
  ck_assert_double_nan(s21_cos(-INFINITY));
  ck_assert_double_eq_tol(cos(M_PI / 2), s21_cos(s21_PI / 2), 1e-7);
  ck_assert_double_eq_tol(cos(-M_PI / 2), s21_cos(-s21_PI / 2), 1e-7);
}
END_TEST

Suite *suite_s21_cos() {
  Suite *cos_1;
  TCase *cos_tc1;

  cos_1 = suite_create("s21_cos");
  cos_tc1 = tcase_create("case_cos");

  tcase_add_test(cos_tc1, test_s21_cos_1);
  tcase_add_test(cos_tc1, test_s21_cos_2);
  tcase_add_test(cos_tc1, test_s21_cos_3);
  tcase_add_test(cos_tc1, test_s21_cos_4);
  tcase_add_test(cos_tc1, test_s21_cos_5);
  tcase_add_test(cos_tc1, test_s21_cos_6);
  tcase_add_test(cos_tc1, test_s21_cos_7);
  tcase_add_test(cos_tc1, test_s21_cos_8);
  tcase_add_test(cos_tc1, test_s21_cos_9);
  tcase_add_test(cos_tc1, test_s21_cos_10);
  tcase_add_test(cos_tc1, test_s21_cos_11);
  tcase_add_test(cos_tc1, test_s21_cos_12);
  tcase_add_test(cos_tc1, test_s21_cos_13);
  tcase_add_test(cos_tc1, test_s21_cos_14);

  suite_add_tcase(cos_1, cos_tc1);

  return cos_1;
}
