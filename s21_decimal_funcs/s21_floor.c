#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int output = OK;
  *result = s21_init_decimal();
  int exponent = s21_get_scale(value), sign = s21_get_sign(value);
  s21_init_decimal(result);
  if (s21_is_decimal_correct(value) == 1) {
    output = CALCULATION_ERROR;
  } else {
    if (exponent > 0) {
      if (sign == 1) {
        s21_decimal one = {0};
        s21_init_decimal(one);
        one.bits[0] = 1;
        s21_decimal temp = {0};
        s21_init_decimal(temp);
        s21_truncate(value, &temp);
        s21_sub(temp, one, result);
      } else
        s21_truncate(value, result);
    } else {
      for (int i = 0; i <= 3; i++) result->bits[i] = value.bits[i];
    }
  }
  return output;
}