#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int output = CALCULATION_ERROR;
  *dst = s21_init_decimal();
  if (src < 0) {
    src *= -1;
    s21_set_sign(dst, 1);
  }
  output = OK;
  dst->bits[0] = src;
  return output;
}