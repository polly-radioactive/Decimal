#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int output = OK, remainder = 0;
  *result = s21_init_decimal();
  int scale = s21_get_scale(value);
  int sign = s21_get_sign(value);
  if (s21_is_decimal_correct(value) == 1) {
    output = CALCULATION_ERROR;
  } else {
    if (scale > 0) {
      s21_set_scale(result, 0);
      while (scale > 0) {
        remainder = s21_divide_by_10(&value);
        scale--;
      }
      s21_set_scale(&value, 0);
      if (remainder >= 5) {
        s21_decimal one = {0};
        s21_init_decimal(one);
        one.bits[0] = 1;
        s21_decimal temp = {0};
        s21_init_decimal(temp);
        if (sign == 1) {
          s21_sub(value, one, result);
        } else {
          s21_add(value, one, result);
        }
      } else
        s21_truncate(value, result);
    } else {
      for (int i = 0; i <= 3; i++) result->bits[i] = value.bits[i];
    }
  }
  s21_print_binary(result->bits[0]);
  return output;
}
