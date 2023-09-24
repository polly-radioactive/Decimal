#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int output = CALCULATION_ERROR;
  *dst = 0;
  int exponent = s21_get_scale(src);
  if (exponent > 0 && exponent < 29) s21_truncate(src, &src);
  if (src.bits[1] == 0 && src.bits[2] == 0 && src.bits[0] <= INT_MAX) {
    *dst = src.bits[0];
    if (s21_get_sign(src) == 1) *dst *= (-1);
    output = OK;
  }
  return output;
}