#include "s21_math.h"
int s21_abs(int x) {
    // возвращает модуль числа
    return x > 0 ? x : -x;
}
long double s21_sqrt(double x) {
  long double result = 4, temp = 0;
  while (s21_fabs(result - temp) > s21_EPS) {
  //   пока result != temp
    if (x < 0) {
        //   при отрицательных числах
      result = -s21_NAN;
      break;
    }
    temp = result;
    result = (temp + x / temp) / 2;
  }
    return x != x ? s21_NAN : result;
}
long double s21_exp(double x) {
    double itog = 1, temp = 1;
    double i = 1;
     if (x == s21_INFINITY) {
      itog = x;  //  выход в реальной функции
    } else if (x == -s21_INFINITY) {
      itog = 0;  //  выход в реальной функции
    } else if (x > 709) {
      itog = s21_INFINITY;  //  выход в реальной функции
    } else if (x < -709) {
      itog = 0;  //  выход в реальной функции
    } else if (x != 0) {
        int f;
        if (x < 0)
            f = 1;
        else
            f = 0;
        x = s21_fabs(x);
        for (; temp >= s21_EPS; ++i) {
            // temp > погрешности
          temp *= x / i;
          itog += temp;
        }
        if (f == 1)
            // если x отриц.
            itog = 1 / itog;
    } else {
        itog = 1;
    }
    return itog;
}
long double s21_fmod(double x, double y) {
    double itog = 0;
    if ((x && y) || y != 0)
        itog = (x / y - (int)(x / y)) * y;  // формула вычисления остатка
    else
        itog = s21_NAN;
    return itog;
}
long double s21_ceil(double x) {
    int num = x;
    long double result;
    if (x == s21_INFINITY || x == -s21_INFINITY) {
        result = x;
    } else if (x == num || x < (long double)num) {
        result = num;
    } else if (x > (long double)num) {
        result = num + 1;
    }
    return x != x ? s21_NAN : result;
}
long double s21_fabs(double x) {
    // модуль с плавающей точкой
    long double result = x;
    if (result < 0) result *= -1;
    return result;
}
long double s21_floor(double x) {
    int num = x;
    long double result;
    if (x == s21_INFINITY || x == -s21_INFINITY) {
        result = x;
    } else if (x == num  || x > (long double)num) {
        result = num;
    } else if (x < (long double)num) {
        result = num - 1;
    }
    return x != x ? s21_NAN : result;
}

long double s21_log(double x) {
    long double itog = 0;
      if (x != x || x == -s21_INFINITY || x < 0) {
          itog = -s21_NAN;  // значения в реал функции
      } else if (x == s21_INFINITY) {
          itog = x;
      }  else if (x == 0) {
          itog = -s21_INFINITY;
      } else {
          if (x >= 0.1 && x <= 10) {
              if (x < 2) {
                  x--;
                  long double result = x, temp = x;
                  long double i = 2;
                  while (s21_fabs(result) > s21_EPS) {
                      // пока резалт не приблизиться к  0
                     result *= -x * (i - 1) / i;
                     i += 1;
                     temp += result;
                   }
                  itog = temp;
          } else  {
                      x = (x / (x - 1));
                      for (int i = 1; i < 1000; i++) {
                          itog += 1.0 / (i * light_pow(x, i));
                      }
          }
        } else {
          int exp = 0;
          if (x > 10) {
            while (x > 10) {
              x /= 10;
              exp++;
            }
          } else {
            while (x < 0.1) {
              x *= 10;
              exp--;
            }
          }
            itog = s21_log(x) + exp * E_10;
        }
      }
      return itog;
}
long double light_pow(double x, int y) {
    double result = 1;
      for (int i = 0; i < y; ++i)
          result *= x;
      return result;
}
long double s21_pow(double base, double exp) {
    long double result;
    if (base < 0) {
      if ((long int)exp == exp) {
        if (exp > 0) {
            result = base;
            for (long int i = 0; i < (long int)exp - 1; i++) {
                result *= base;
          }
        } else if (exp == 0) {
            result = 1;
        } else {
            result = 1 / base;
            for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
              result /= base;
          }
        }
      } else {
        if (exp == -s21_INFINITY || exp == s21_INFINITY) {
          if (base * (-1) < 1) {
              result = 0;
          } else if (base * (-1) == 1) {
              result = 1;
          } else {
            if (exp == -s21_INFINITY) {
                result = 0;
            } else {
                result = s21_INFINITY;
            }
        }
        } else {
            result = -s21_NAN;
        }
      }
    } else if (base == 0) {
      if (exp == 0) {
          result = 1;
      } else if (exp <= 0) {
          result = s21_INFINITY;
      } else {
          result = 0;
      }
    } else if (base == 1) {
        result = 1;
    } else if (base == s21_NAN || base == -s21_NAN) {
        result = base;
    } else {
      if ((long int)exp == exp) {
        if (exp > 0) {
            result = base;
            for (long int i = 0; i < (long int)exp - 1; i++) {
                result *= base;
          }
        } else if (exp == 0) {
            result = 1;
        } else {
            result = 1 / base;
            for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
                result /= base;
          }
        }
      } else {
          result = s21_exp(exp * (double)s21_log(base));
      }
    }
    return result;
}
long double s21_sin(double x) {
    while (x > PI || x < -PI) {
        x += x > PI ? -2 * PI : 2 * PI;
      }
    long double result = x, itog = x;
    long double i = 1.;
    while (s21_fabs(result) > s21_EPS) {
        result = -1 * result * x * x / (2 * i * (2 * i + 1));
        i += 1.;
        itog += result;
  }
    return itog;
}
long double s21_cos(double x) {
    while (x > PI || x < -PI) {
        x += x > PI ? -2 * PI : 2 * PI;
      }
  return s21_sin(PI / 2 - x);
}
long double s21_tan(double x) {
  long double y = 0;
  if (x != x || x == s21_INFINITY || x == -s21_INFINITY) {
    y = -s21_NAN;
  } else {
    long double sin = s21_sin(x), cos = s21_cos(x);
    if (cos == 0) {
        y = (sin > 0) ? s21_INFINITY : -s21_INFINITY;
    } else {
      y = sin / cos;
    }
  }
  return y;
}
long double s21_atan(double x) {
    long double temp = 0;
    temp = (x < 1 && x > -1) ? a_count(x) : temp;
    temp =  x == 1 ? PI / 4: x == -1 ? -PI / 4: x == 0 ? 0 : temp;
    temp = x > 1 ? PI / 2 - a_count(1 / x): x < -1 ? -PI/2 -a_count(1 / x): temp;
    return temp;
}

long double a_count(double x) {
  long double result = x, temp = x, i = 1;
  while (s21_fabs(result) > s21_EPS) {
    result = -1 * result * x * x * (2 * i - 1) / (2 * i + 1);
    i += 1;
    temp += result;
  }
  return temp;
}

long double s21_asin(double x) {
    long double result = x, temp = x;
    long double i = 1;
    while (s21_fabs(result) > s21_EPS) {
        if (x < -1 || x > 1) {
            temp = s21_NAN;
            break;
        }
        if (x == 1 || x == -1) {
            temp = PI / 2 * x;
            break;
        }
        result *= x * x * (2 * i - 1) * (2 * i) * (2 * i - 1) / ((2 * i + 1) * 4 * i * i);
        i += 1;
        temp += result;
    }
    return temp;
}

long double s21_acos(double x) {
    return (x <= 1 && x >= -1) ? s21_abs(x) == 1 ? PI * (1 - x) / 2 : PI / 2. - s21_asin(x) : s21_NAN;
}
