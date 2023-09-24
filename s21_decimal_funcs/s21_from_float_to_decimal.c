#include "../s21_decimal.h"

int s21_from_float_to_decimal(float input, s21_decimal *dest) {
  s21_init_decimal(dest);
  if (dest == NULL || s21_is_correct_float(input)) return 1;
  long double src = input;
  int sign_1 = 1;
  int output = OK, sign = 0;
  (src < 0) ? (sign = 1) : (sign = 0);
  src = fabsl(src);
  if (pow(10, -28) <= src && src < pow(2, 96) && src >= -(pow(2, 96) - 1)) {
    int scale = 0;
    /*если до точки меньше 7 знаков, то домножаем, пока 7 не станет*/
    while (src < 999999 && scale < 28) {
      src *= 10;
      scale++;
    }
    // большое число сокращаем до 7 знаков
    while (src > 9999999) {
      src /= 10;
      scale--;
    }
    // printf("src before round %Lf\n", src);
    src = round(src);
    int temp = (int)src;
    dest->bits[0] = temp;
    // printf("temp %d\n", temp);
    /*убираем нули, вдруг число такое большое
    и в нем много нулей, нафиг они нужны*/
    while (scale > 0 && dest->bits[0] % 10 == 0) {
      scale--;
      div_by_10(dest);
    }
    while (scale < 0) {
      mult_by_10(dest);
      scale++;
    }
    // printf("scale %d\n", scale);
    s21_set_scale(dest, scale);
    if (sign) s21_set_sign(dest, sign_1);
  } else {
    output = CALCULATION_ERROR;
  }
  return output;
}

int s21_is_correct_float(float src) {
  int output = 0;
  if (isnan(src) || isinf(src) || max_decimal < src || src < -(max_decimal) ||
      (src > 0 && src < 1e-28) || (src < 0 && src > -1e-28)) {
    output = 1;
  }
  return output;
}

int s21_get_binary_exp(float src) {
  int result = 0;
  int fbits = *((unsigned int *)&src);
  if (fbits & (1 << 31)) src *= -1;
  fbits >>= 23;
  result = fbits - 127;
  return result;
}
