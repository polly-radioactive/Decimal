#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res;
  int scale;
  int sign;
  s21_long_decimal long_v_1;
  s21_long_decimal long_v_2;
  s21_long_decimal long_mul;
  clean_long_decimal(&long_v_1);
  clean_long_decimal(&long_v_2);
  clean_long_decimal(&long_mul);
  from_decimal_to_long(value_1, &long_v_1);
  from_decimal_to_long(value_2, &long_v_2);
  sign = sign_dm(value_1, value_2);
  if (sign == 0) {  // определение знака
    res = 1;
  } else {
    res = 2;
  }
  if (mul_long_decimal(long_v_1, long_v_2, &long_mul) == 0) {  // умножение
    scale =
        shortening(&long_mul, s21_get_scale(value_1) + s21_get_scale(value_2));
    if (scale >= 0) {  // проверка на переполнение
      clean(result);   // очистка перед записью
      from_long_to_decimal(long_mul, result);  // копирование в децимал
      s21_set_scale(result, scale);
      s21_set_sign(result, sign);
      res = 0;
    }
  }
  return res;
}
