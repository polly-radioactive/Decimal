#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int return_value = 0;
  int value_1_sign = s21_get_sign(value_1);
  int value_1_exp = s21_get_scale(value_1);
  int value_2_sign = s21_get_sign(value_2);
  int value_2_exp = s21_get_scale(value_2);
  int tmp = s21_get_first_bit(value_1) + s21_get_first_bit(value_2);
  if (value_1_exp > 28 || value_2_exp > 28) {
    return_value = 0;
  } else {
    if (tmp != -2) {
      if (value_1_sign == 1 && value_2_sign == 0) {
        return_value = 1;
      } else if (value_1_sign == value_2_sign) {
        scale_equalize(&value_1, &value_2);
        for (int i = 95; i >= 0; i--) {
          tmp = s21_get_bit(value_1, i) - s21_get_bit(value_2, i);
          if (value_1_sign == 0) {
            if (tmp == 1) {
              i = -1;
            }
            if (tmp == -1) {
              return_value = 1;
              i = -1;
            }
          } else {
            if (tmp == -1) {
              i = -1;
            }
            if (tmp == 1) {
              return_value = 1;
              i = -1;
            }
          }
        }
      }
    }
  }
  return return_value;
}
