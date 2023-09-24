#include "../s21_decimal.h"

// деление двух децималов

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (is_zero_decimal(value_2)) {
    int scale = 0;
    int res_scale = 0;
    clean(result);
    s21_long_decimal long_v_1;
    s21_long_decimal long_v_2;
    s21_long_decimal long_div;
    clean_long_decimal(&long_v_1);
    clean_long_decimal(&long_v_2);
    clean_long_decimal(&long_div);
    from_decimal_to_long(value_1, &long_v_1);
    from_decimal_to_long(value_2, &long_v_2);
    s21_set_sign(result, sign_dm(value_1, value_2));  // установка знака
    scale = div_long_decimal(long_v_1, long_v_2, &long_div);
    s21_set_scale(&value_1, s21_get_scale(value_1) + scale);
    res_scale = s21_get_scale(value_1) - s21_get_scale(value_2);
    if (res_scale > 0) {
      res_scale = shortening(&long_div, res_scale);
    } else if (res_scale < 0) {
      increase_scale_long_decimal(&long_div, abs(res_scale));
      res_scale = shortening(&long_div, 0);
    }
    if (res_scale >= 0) {
      from_long_to_decimal(long_div, result);
      s21_set_scale(result, res_scale);
    } else {
      res = 1;
    }
  } else {
    res = 3;
  }
  if (res == 1 && s21_get_sign(*result)) {
    res = 2;
  }
  if (res) {
    clean(result);
  }
  return res;
}
