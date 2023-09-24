#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result) {
    int exponent = s21_get_scale(value);
    *result = s21_init_decimal();  // занулим result
    if (exponent > 0) {
      while (exponent > 0) {
        s21_divide_by_10(&value);
        exponent--;
      }
    }
    s21_set_scale(&value, 0);
    for (int i = 0; i <= 3; i++) result->bits[i] = value.bits[i];
  }
  return OK;
}