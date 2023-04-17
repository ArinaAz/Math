// Copyright 2022 <Lettersb Roxannas Merlinli>
#include "s21_math.h"
#include <math.h>
#include <check.h>
START_TEST(test_abs) {
    for (int i = -99; i < 99; i++)
        ck_assert_int_eq(s21_abs(i), abs(i));
}
END_TEST
START_TEST(test_acos) {
    double x = 0.43;
    ck_assert_uint_eq(s21_acos(x), acos(x));
    x = -1;
    ck_assert_uint_eq(s21_acos(x), acos(x));
    x = -0.999;
    ck_assert_uint_eq(s21_acos(x), acos(x));
    for (double i = -10.; i < 180.; i += 1.) {
        ck_assert_uint_eq(s21_acos(i), acos(i));
    }
    for (double i = -1; i < 180; i += 0.01) {
        ck_assert_uint_eq(s21_acos(i), acos(i));
    }
}
END_TEST
START_TEST(test_asin) {
    double x = 0.43;
    ck_assert_uint_eq(s21_asin(x), asin(x));
    x = 0.12;
    ck_assert_uint_eq(s21_asin(x), asin(x));
    ck_assert_ldouble_nan(s21_asin(s21_INFINITY));
    ck_assert_ldouble_nan(asin(s21_INFINITY));
    ck_assert_ldouble_nan(s21_asin(-s21_INFINITY));
    ck_assert_ldouble_nan(asin(-s21_INFINITY));
    ck_assert_ldouble_nan(s21_asin(s21_NAN));
    ck_assert_ldouble_nan(asin(s21_NAN));
    ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), s21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), s21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), s21_EPS);
    ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), s21_EPS);
    x = 0.43;
    ck_assert_uint_eq(s21_asin(x), asin(x));
    x = 0.12;
    ck_assert_uint_eq(s21_asin(x), asin(x));
    for (double i = 0.; i < 2; i += 1) {
        ck_assert_uint_eq(s21_asin(i), asin(i));
    }
    for (double i = -1; i < 5; i += 0.01) {
        ck_assert_uint_eq(s21_asin(i), asin(i));
    }
}
END_TEST
START_TEST(test_atan) {
    double x = 0.43;
    ck_assert_uint_eq(s21_atan(x), atan(x));
    x = 0.12;
    ck_assert_uint_eq(s21_atan(x), atan(x));
    x = 1;
    ck_assert_uint_eq(s21_atan(x), atan(x));
    x = -1;
    ck_assert_uint_eq(s21_atan(x), atan(x));
    x = 0;
    ck_assert_uint_eq(s21_atan(x), atan(x));
    x = 12345;
    ck_assert_uint_eq(s21_atan(x), atan(x));
    x = 0.001;
    ck_assert_uint_eq(s21_atan(x), atan(x));
    x = -12345;
    ck_assert_uint_eq(s21_atan(x), atan(x));
    for (double i = -1; i <= 1; i += 0.01) {
        ck_assert_uint_eq(s21_atan(i), atan(i));
    }
}
END_TEST
START_TEST(test_ceil) {
    double x = 1.5;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
    x = 0.45;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
    x = -3.01;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
    x = -0;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
    x = 1234567;
    ck_assert_int_eq(s21_ceil(x), ceil(x));
    x = s21_INFINITY;
    ck_assert_uint_eq(s21_ceil(x), ceil(x));
}
END_TEST
START_TEST(test_cos) {
    double x = 0;
    ck_assert_uint_eq(s21_cos(x), cos(x));
    x = 112343;
    ck_assert_uint_eq(s21_cos(x), cos(x));
    x = -312345;
    ck_assert_uint_eq(s21_cos(x), cos(x));
    for (double i = -PI; i < PI; i+= 0.01) {
        ck_assert_uint_eq(s21_cos(i), cos(i));
    }
}
END_TEST
START_TEST(test_exp) {
    ck_assert_uint_eq(s21_exp(s21_INFINITY), exp(s21_INFINITY));
    ck_assert_uint_eq(s21_exp(1.56), exp(1.56));
    ck_assert_uint_eq(s21_exp(-0.95), exp(-0.95));
    ck_assert_uint_eq(s21_exp(1234567), exp(1234567));
    ck_assert_uint_eq(s21_exp(-1234567), exp(-1234567));
    for (double i = -10; i < 10; i++) {
        ck_assert_uint_eq(s21_exp(i), exp(i));
    }
}
END_TEST
START_TEST(test_fabs) {
    for (double i = -20; i < 20; i += 0.01) {
        ck_assert_ldouble_eq(s21_fabs(i), fabs(i));
    }
}
END_TEST
START_TEST(test_floor) {
    double x = 1.5;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
    x = 0.45;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
    x = -3.01;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
    x = -0.;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
    x = -0.;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
    x = s21_INFINITY;
    ck_assert_uint_eq(s21_floor(x), floor(x));
}
END_TEST
START_TEST(test_fmod) {
    double x = 10;
    double y = 0;
    ck_assert_uint_eq(s21_fmod(x, y), fmod(x, y));
    for (double i = -200; i < 200; i += 0.91) {
        for (double j = -50; j < 50; j += 0.91) {
            ck_assert_uint_eq(s21_fmod(i, j), fmod(i, j));
        }
    }
}
END_TEST
START_TEST(test_log) {
    ck_assert_uint_eq(s21_log(987654), log(987654));
    ck_assert_uint_eq(s21_log(1.119), log(1.119));
    ck_assert_uint_eq(s21_log(s21_INFINITY), log(s21_INFINITY));
    for (double i = -1.; i < 10; i+= 0.5) {
        ck_assert_uint_eq(s21_log(i), log(i));
    }
    for (double i = 0.; i < 2; i+= 0.01) {
        ck_assert_uint_eq(s21_log(i), log(i));
    }
}
END_TEST
START_TEST(test_pow) {
    long double base = -10.1261;
    long double exp = -0.72;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
     base = -0;
    exp = s21_INFINITY;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
    exp = 123;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
    base = -1;
    exp = s21_NAN;
    ck_assert_double_nan(pow(base, exp));
    ck_assert_double_nan(s21_pow(base, exp));
    exp = s21_INFINITY;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
    base = s21_NAN;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
    exp = -123;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
    base = -123;
    exp = s21_NAN;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
    base = 1.55;
    exp = -s21_INFINITY;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
    base = -s21_INFINITY;
    exp = -193;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
    base = -1.55;
    exp = 0;
    ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_EPS);
    base = 0;
    exp = 0;
    ck_assert_uint_eq(s21_pow(base, exp), pow(base, exp));
    base = s21_NAN;
    exp = 12;
    ck_assert_double_nan(s21_pow(base, exp));
    ck_assert_double_nan(pow(base, exp));
    for (double i = -10; i < 10; i += 0.1) {
        for (double j = 1; j < 10; j += 1) {
            ck_assert_uint_eq(s21_pow(i, j), pow(i, j));
        }
    }
    for (double i = -10; i < 10; i += 1) {
        for (double j = 1; j < 10; j += 1) {
            ck_assert_uint_eq(s21_pow(i, j), pow(i, j));
        }
    }
    ck_assert_uint_eq(s21_pow(312, 0), pow(312, 0));
    ck_assert_uint_eq(s21_pow(-s21_NAN, 0), pow(-s21_NAN, 0));
}
END_TEST
START_TEST(test_sin) {
    double x = 0;
    ck_assert_uint_eq(s21_sin(x), sin(x));
     x = 1234567;
    ck_assert_uint_eq(s21_sin(x), sin(x));
    x = -3234567;
    ck_assert_uint_eq(s21_sin(x), sin(x));
    for (double i = -PI; i < PI; i+= 0.01) {
        ck_assert_uint_eq(s21_sin(i), sin(i));
    }
}
END_TEST
START_TEST(test_sqrt) {
    for (double i = -1.; i < 100; i+=1) {
        ck_assert_uint_eq(s21_sqrt(i), sqrt(i));
    }
    for (double i = 0; i < 1; i+=0.001) {
        ck_assert_uint_eq(s21_sqrt(i), sqrt(i));
    }
}
END_TEST
START_TEST(test_tan) {
    double x = 0.23;
    ck_assert_uint_eq(s21_tan(x), tan(x));
    x = 1234567;
    ck_assert_uint_eq(s21_tan(x), tan(x));
    x = -1234567;
    ck_assert_uint_eq(s21_tan(x), tan(x));
    for (double i = -100; i < 100; i += 2) {
        ck_assert_uint_eq(s21_tan(i), tan(i));
    }
    for (double i = -1; i < 1; i += 0.02) {
        ck_assert_uint_eq(s21_tan(i), tan(i));
    }
    x = s21_INFINITY;
    ck_assert_uint_eq(s21_tan(x), tan(x));
}
END_TEST

int main(void) {
    Suite *s = suite_create("Core");
    TCase *tc_core = tcase_create("Core");
    SRunner *sr = srunner_create(s);
    int number_fail = 0;
    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_abs);
    tcase_add_test(tc_core, test_acos);
    tcase_add_test(tc_core, test_asin);
    tcase_add_test(tc_core, test_atan);
    tcase_add_test(tc_core, test_ceil);
    tcase_add_test(tc_core, test_cos);
    tcase_add_test(tc_core, test_exp);
    tcase_add_test(tc_core, test_fabs);
    tcase_add_test(tc_core, test_floor);
    tcase_add_test(tc_core, test_fmod);
    tcase_add_test(tc_core, test_log);
    tcase_add_test(tc_core, test_pow);
    tcase_add_test(tc_core, test_sin);
    tcase_add_test(tc_core, test_sqrt);
    tcase_add_test(tc_core, test_tan);
    srunner_run_all(sr, CK_NORMAL);
    number_fail = srunner_ntests_failed(sr);
    srunner_free(sr);
    number_fail = (number_fail != 0) ? 1 : 0;
    return number_fail;
}

