#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = s21_init_decimal();
  for (int i = 0; i <= 3; i++) result->bits[i] = value.bits[i];
  s21_inverse_bit(result, 127);
  return OK;
}