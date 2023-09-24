#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign_2 = 0, s21_error = 0;
  sign_2 = s21_get_sign(value_2);
  s21_set_sign(&value_2, !(sign_2));
  s21_error = s21_add(value_1, value_2, result);
  return s21_error;
}

int sub_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_init_decimal(result);
  int left = 0, right = 0, j = 0, sign_1 = 1, sign_0 = 0;
  for (int i = 0; i < 96; i++) {
    left = s21_get_bit(value_1, i);
    right = s21_get_bit(value_2, i);
    if (left != right) {
      s21_set_bit(result, i, sign_1);
    } else {
      s21_set_bit(result, i, sign_0);
    }
    if (!left && right) {
      j = i + 1;
      while (s21_get_bit(value_1, j) != 1 && j != 95) {
        s21_set_bit(&value_1, j, sign_1);
        j++;
      }
      s21_set_bit(&value_1, j, sign_0);
    }
  }
  return 0;
}

int bigger_scale(s21_decimal val1, s21_decimal val2) {
  int meow = 0;
  int scale_1 = 0;
  scale_1 = s21_get_scale(val1);
  int scale_2 = 0;
  scale_2 = s21_get_scale(val2);
  if (scale_1 > scale_2) {
    meow = scale_1;
  } else {
    meow = scale_2;
  }
  return meow;
}
