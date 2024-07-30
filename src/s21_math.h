#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>

#define s21_PI 3.14159265358979323846264338327950288
#define s21_NPI -3.14159265358979324
#define s21_EPS 1e-17
#define s21_ln10 2.30258509299404590109
#define s21_INF 1.0 / 0.0
#define s21_NINF -1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_N_NAN -0.0 / 0.0
#define s21_MAX_double 1.7976931348623157e308
#define s21_M_E 2.71828182845904523536028747135266250
#define s21_LOG_10 2.30258509299
#define s21_LOG_2 0.69314718056
#define s21_PI_2 1.57079632

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp1);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
#endif