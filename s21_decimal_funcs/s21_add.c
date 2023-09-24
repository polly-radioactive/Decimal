#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int value_1_sign = 0, value_2_sign = 0, s21_error = 0, scale = 0, sign_0 = 0;

  value_1_sign = s21_get_sign(value_1);
  value_2_sign = s21_get_sign(value_2);

  scale_equalize(&value_1, &value_2);
  scale = bigger_scale(value_1, value_2);
  //  s21_set_scale(result, scale);

  s21_set_sign(&value_1, sign_0);
  s21_set_sign(&value_2, sign_0);

  if (value_1_sign != value_2_sign) {  // если знаки не одинаковы
    if (s21_is_greater(value_1, value_2)) {
      s21_error = sub_simple(value_1, value_2, result);
      s21_set_sign(result, value_1_sign);
    } else {
      s21_error = sub_simple(value_2, value_1, result);
      s21_set_sign(result, value_2_sign);
    }
  } else {  // если знаки одинаковы
    s21_error = add_simple(value_1, value_2, result);
    s21_set_sign(result, value_1_sign);
  }
  s21_set_scale(result, scale);

  return (s21_handle_error(s21_error, value_1_sign, value_2_sign));
}

int add_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_init_decimal(result);
  int extra = 0, val1 = 0, val2 = 0;
  int sign_1 = 1, sign_0 = 0;
  for (int i = 0; i < 96; i++) {
    val1 = s21_get_bit(value_1, i);
    val2 = s21_get_bit(value_2, i);
    if (val1 == 1 && val2 == 0 && extra == 0) {
      s21_set_bit(result, i, sign_1);
    } else if (val1 == 0 && val2 == 1 && extra == 0) {
      s21_set_bit(result, i, sign_1);
    } else if (val1 == 0 && val2 == 0 && extra == 1) {
      s21_set_bit(result, i, sign_1);
    } else if (val1 == 1 && val2 == 1 && extra == 1) {
      s21_set_bit(result, i, sign_1);
    } else {
      s21_set_bit(result, i, sign_0);
    }
    extra = ((val1 && val2) || (val2 && extra) || (val1 && extra));
  }
  return extra;
}

int s21_handle_error(int error, int sign_1, int sign_2) {
  int s21_error = 0;
  if (error) {
    if (sign_1 && sign_2) {
      s21_error = 2;
    } else {
      s21_error = 1;
    }
  }
  return s21_error;
}
