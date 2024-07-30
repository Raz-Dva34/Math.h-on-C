#include "suitcases.h"

START_TEST(test_s21_fmod_1) {
  double d = 0, y = 0;
  ck_assert_int_eq(isnan(fmod(d, y)), isnan(s21_fmod(d, y)));
}
END_TEST

START_TEST(test_s21_fmod_2) {
  double d = -0, y = -0;
  ck_assert_int_eq(isnan(fmod(d, y)), isnan(s21_fmod(d, y)));
}
END_TEST

START_TEST(test_s21_fmod_3) {
  double d = 0.5, y = 0.9;
  ck_assert_double_eq_tol(fmod(d, y), s21_fmod(d, y), 0.000001);
}
END_TEST

START_TEST(test_s21_fmod_4) {
  double d = 51.5, y = 25.3;
  ck_assert_double_eq_tol(fmod(d, y), s21_fmod(d, y), 0.000001);
}
END_TEST

START_TEST(test_s21_fmod_5) {
  double d = -0.5, y = -0.4;
  ck_assert_double_eq_tol(fmod(d, y), s21_fmod(d, y), 0.000001);
}
END_TEST

START_TEST(test_s21_fmod_6) {
  double d = -75.5, y = -25.3;
  ck_assert_double_eq_tol(fmod(d, y), s21_fmod(d, y), 0.000001);
}
END_TEST

START_TEST(test_s21_fmod_7) {
  double d = s21_NAN, y = s21_NAN;
  ck_assert_int_eq(isnan(fmod(d, y)), isnan(s21_fmod(d, y)));
}
END_TEST

START_TEST(test_s21_fmod_8) {
  double d = s21_INF, y = s21_INF;
  ck_assert_int_eq(isnan(fmod(d, y)), isnan(s21_fmod(d, y)));
}
END_TEST

START_TEST(test_s21_fmod_9) {
  double d = s21_NINF, y = s21_NINF;
  ck_assert_int_eq(isnan(fmod(d, y)), isnan(s21_fmod(d, y)));
}
END_TEST

START_TEST(test_s21_fmod_10) {
  ck_assert_double_nan(fmod(1, 0));
  ck_assert_double_nan(s21_fmod(1, 0));
  ck_assert_double_eq(fmod(0, -1), s21_fmod(0, -1));
  ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
  ck_assert_double_nan(fmod(INFINITY, -1));
  ck_assert_double_nan(s21_fmod(s21_INF, -1));
  ck_assert_double_eq(fmod(-1, -INFINITY), s21_fmod(-1, s21_NINF));
  ck_assert_double_eq(fmod(0, INFINITY), s21_fmod(0, s21_INF));
  ck_assert_double_nan(s21_fmod(0, s21_NAN));
  ck_assert_double_nan(fmod(0, NAN));
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_INF));
  ck_assert_double_nan(s21_fmod(s21_INF, s21_NAN));
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_NINF));
  ck_assert_double_nan(s21_fmod(s21_NINF, s21_NAN));
  ck_assert_double_nan(fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, NAN));
  ck_assert_double_nan(fmod(NAN, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(test_s21_fmod_11) {
  for (double a = -1500; a < 1500; a += 123) {
    for (double b = -12; b < 12; b += 1.25) {
      ck_assert_double_eq(fmod(a, b), s21_fmod(a, b));
      ck_assert_double_eq(fmod(b, a), s21_fmod(b, a));
    }
  }
}
END_TEST

Suite *suite_s21_fmod() {
  Suite *fmod_1;
  TCase *fmod_tc1;

  fmod_1 = suite_create("s21_fmod");
  fmod_tc1 = tcase_create("case_fmod");

  tcase_add_test(fmod_tc1, test_s21_fmod_1);
  tcase_add_test(fmod_tc1, test_s21_fmod_2);
  tcase_add_test(fmod_tc1, test_s21_fmod_3);
  tcase_add_test(fmod_tc1, test_s21_fmod_4);
  tcase_add_test(fmod_tc1, test_s21_fmod_5);
  tcase_add_test(fmod_tc1, test_s21_fmod_6);
  tcase_add_test(fmod_tc1, test_s21_fmod_7);
  tcase_add_test(fmod_tc1, test_s21_fmod_8);
  tcase_add_test(fmod_tc1, test_s21_fmod_9);
  tcase_add_test(fmod_tc1, test_s21_fmod_10);
  tcase_add_test(fmod_tc1, test_s21_fmod_11);

  suite_add_tcase(fmod_1, fmod_tc1);

  return fmod_1;
}