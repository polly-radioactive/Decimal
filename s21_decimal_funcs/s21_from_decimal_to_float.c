#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0;
  int output = CALCULATION_ERROR;
  long double sum = 0;
  int index = 0;
  s21_find_non_zero_bit(src, &index);
  for (; index >= 0; index--) {
    if (s21_get_bit(src, index) == 1) sum += pow(2, index);
  }
  int scale = s21_get_scale(src);
  while (scale != 0) {
    sum /= 10.0;
    --scale;
  }
  *dst = (float)sum;
  if (s21_get_sign(src)) *dst *= -1;
  output = OK;
  return output;
}