#include "suitcases.h"

START_TEST(test_s21_acos_1) {
  double d = 0;
  ck_assert_double_eq_tol(acos(d), s21_acos(d), 0.000001);
}
END_TEST

START_TEST(test_s21_acos_2) {
  double d = -0;
  ck_assert_double_eq_tol(acos(d), s21_acos(d), 0.000001);
}
END_TEST

START_TEST(test_s21_acos_3) {
  double d = 0.3;
  ck_assert_double_eq_tol(acos(d), s21_acos(d), 0.000001);
}
END_TEST

START_TEST(test_s21_acos_4) {
  double d = 1.3;
  ck_assert_int_eq(isnan(acos(d)), isnan(s21_acos(d)));
}
END_TEST

START_TEST(test_s21_acos_5) {
  double d = -7;
  ck_assert_int_eq(isnan(acos(d)), isnan(s21_acos(d)));
}
END_TEST

START_TEST(test_s21_acos_6) {
  double d = -12.5;
  ck_assert_int_eq(isnan(acos(d)), isnan(s21_acos(d)));
}
END_TEST

START_TEST(test_s21_acos_7) {
  double d = s21_NAN;
  ck_assert_int_eq(isnan(acos(d)), isnan(s21_acos(d)));
}
END_TEST

START_TEST(test_s21_acos_8) {
  double d = s21_NINF;
  ck_assert_int_eq(isnan(acos(d)), isnan(s21_acos(d)));
}
END_TEST

START_TEST(test_s21_acos_9) {
  double d = s21_INF;
  ck_assert_int_eq(isnan(acos(d)), isnan(s21_acos(d)));
}
END_TEST

START_TEST(test_s21_acos_10) {
  double d = 0.99999;
  ck_assert_double_eq_tol(acos(d), s21_acos(d), 0.000001);
}
END_TEST

START_TEST(test_s21_acos_11) {
  double d = 0.000001;
  ck_assert_double_eq_tol(acos(d), s21_acos(d), 0.000001);
}
END_TEST

START_TEST(test_s21_acos_12) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(test_s21_acos_13) {
  for (float k = -1; k <= 1; k += 0.0305) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

Suite *suite_s21_acos() {
  Suite *acos_1;
  TCase *acos_tc1;

  acos_1 = suite_create("s21_acos");
  acos_tc1 = tcase_create("case_acos");

  tcase_add_test(acos_tc1, test_s21_acos_1);
  tcase_add_test(acos_tc1, test_s21_acos_2);
  tcase_add_test(acos_tc1, test_s21_acos_3);
  tcase_add_test(acos_tc1, test_s21_acos_4);
  tcase_add_test(acos_tc1, test_s21_acos_5);
  tcase_add_test(acos_tc1, test_s21_acos_6);
  tcase_add_test(acos_tc1, test_s21_acos_7);
  tcase_add_test(acos_tc1, test_s21_acos_8);
  tcase_add_test(acos_tc1, test_s21_acos_9);
  tcase_add_test(acos_tc1, test_s21_acos_10);
  tcase_add_test(acos_tc1, test_s21_acos_11);
  tcase_add_test(acos_tc1, test_s21_acos_12);
  tcase_add_test(acos_tc1, test_s21_acos_13);

  suite_add_tcase(acos_1, acos_tc1);

  return acos_1;
}