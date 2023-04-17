#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>
#define PI 3.14159265358979324
#define s21_NAN 0.0 / 0.0
#define s21_INFINITY 1.0 / 0.0
#define E 2.718281828459045091
#define s21_EPS 1e-17
#define E_10 2.302585092994046
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
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double light_pow(double x, int y);
long double a_count(double x);
#endif  // SRC_S21_MATH_H_
