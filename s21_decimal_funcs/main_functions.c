#include "../s21_decimal.h"
// newew

//  в каком из 3-х int-массивов находится бит
int s21_get_bit_array(int index) { return index / 32; }

//  под каким номером от 0 до 31 находится бит
int s21_get_bit_array_index(int index) { return index % 32; }

//  посмотреть, 0 или 1 стоит под конкретным индексом
int s21_get_bit(s21_decimal decimal, int index) {
  int mask = 1u << s21_get_bit_array_index(index);
  return (decimal.bits[s21_get_bit_array(index)] & mask) != 0;
}

//  проинициализировать структуру децимала
s21_decimal s21_init_decimal() {
  s21_decimal decimal;
  decimal.bits[0] = 0;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 0;
  return decimal;
}

//  поставить нужный бит в 1 или 0
void s21_set_bit(s21_decimal *decimal, int index, int new_bit) {
  int mask = 1u << s21_get_bit_array_index(index);
  (new_bit == 0) ? (decimal->bits[s21_get_bit_array(index)] &= ~mask)
                 : (decimal->bits[s21_get_bit_array(index)] |= mask);
}

// поменять знак у всего децимал-числа
void s21_set_sign(s21_decimal *decimal, int sign) {
  s21_set_bit(decimal, 127, sign);
}

// узнать, число отрицательное или положительное
int s21_get_sign(s21_decimal decimal) { return s21_get_bit(decimal, 127); }

// инвертнуть конкретный бит
void s21_inverse_bit(s21_decimal *decimal, int index) {
  int mask = 1u << s21_get_bit_array_index(index);
  decimal->bits[s21_get_bit_array(index)] ^= mask;
}

// посмотреть scale (степень)
int s21_get_scale(s21_decimal decimal) {
  int result = 0, scale = 1;
  for (int i = 112; i <= 119; i++) {
    if (s21_get_bit(decimal, i)) result += scale;
    scale <<= 1;
  }
  return result;
}

// установить новый scale
s21_decimal *s21_set_scale(s21_decimal *decimal, int scale) {
  int sign = 0;
  sign = s21_get_sign(*decimal);
  if (scale >= 0 && scale <= 28) {
    decimal->bits[3] &= 0;
    decimal->bits[3] |= (scale <<= 16);
    s21_set_sign(decimal, sign);
  }
  return decimal;
}

// вывести децимал (один из его четырех битов) в двоичном виде
int s21_print_binary(unsigned int x) {
  unsigned int den = 0x80000000, bit = 0;
  // printf("\nin binary: \n");
  while (den > 0) {
    bit = (x & den) ? 1 : 0;
    // printf("%i", bit);
    den >>= 1;
  }
  // printf("\n");
  return bit;
}

// найти первый ненулевой бит
void s21_find_non_zero_bit(s21_decimal decimal, int *index) {
  int i = 95;
  while (i >= 0) {
    if (s21_get_bit(decimal, i)) {
      *index = i;
      break;
    }
    i--;
  }
}

// деление на 10 децимала
int s21_divide_by_10(s21_decimal *decimal) {
  int remainder = 0;
  for (int i = 2; i >= 0; i--) {
    long int_rewriting = (remainder * 0x100000000) + (long)decimal->bits[i];
    decimal->bits[i] = int_rewriting / 10;
    remainder = int_rewriting - (10 * decimal->bits[i]);
  }
  return remainder;
}

int s21_is_decimal_correct(s21_decimal decimal) {
  int res = 0;
  if (s21_get_scale(decimal) < 0 || s21_get_scale(decimal) > 28) {
    res = 1;
  }
  return res;
}

// сдвиг налево
int offset_left(s21_decimal *decimal, int value_offset) {
  int return_value = OK;
  int sign_1 = 1;
  int last_bit = s21_get_last_bit(*decimal);
  if (last_bit + value_offset > 95) {
    return_value = INF;
  } else {
    for (int i = 0; i < value_offset; i++) {
      int value_31bit = s21_get_bit(*decimal, 31);
      int value_63bit = s21_get_bit(*decimal, 63);
      decimal->bits[0] <<= 1;
      decimal->bits[1] <<= 1;
      decimal->bits[2] <<= 1;
      if (value_31bit) s21_set_bit(decimal, 32, sign_1);
      if (value_63bit) s21_set_bit(decimal, 64, sign_1);
    }
  }
  return return_value;
}

// очистка
void clean(s21_decimal *d) {
  if (d) {
    d->bits[0] = 0;
    d->bits[1] = 0;
    d->bits[2] = 0;
    d->bits[3] = 0;
  }
}

// добавление бита
int s21_bit_add(s21_decimal var1, s21_decimal var2, s21_decimal *result) {
  clean(result);
  int return_value = 0;
  int buffer = 0;
  int sign_1 = 1;
  int sign_0 = 0;

  for (int i = 0; i < 96; i++) {
    int current_1 = s21_get_bit(var1, i);
    int current_2 = s21_get_bit(var2, i);

    if (!current_1 && !current_2) {
      if (buffer) {
        s21_set_bit(result, i, sign_1);
        buffer = 0;
      } else {
        s21_set_bit(result, i, sign_0);
      }
    } else if (current_1 != current_2) {
      if (buffer) {
        s21_set_bit(result, i, sign_0);
        buffer = 1;
      } else {
        s21_set_bit(result, i, sign_1);
      }
    } else {
      if (buffer) {
        s21_set_bit(result, i, sign_1);
        buffer = 1;
      } else {
        s21_set_bit(result, i, sign_0);
        buffer = 1;
      }
    }
    if (i == 95 && buffer == 1) return_value = INF;
  }

  return return_value;
}

int s21_get_last_bit(s21_decimal decimal) {
  int i = 95;
  while (i) {
    if (s21_get_bit(decimal, i)) break;
    i--;
  }
  return i;
}

void mul_only_bits(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  clean(result);
  s21_decimal tmp_res;
  int last_bit_1 = s21_get_last_bit(value_1);
  for (int i = 0; i <= last_bit_1; i++) {
    clean(&tmp_res);
    int value_bit_1 = s21_get_bit(value_1, i);

    if (value_bit_1) {
      tmp_res = value_2;
      offset_left(&tmp_res, i);
      s21_bit_add(*result, tmp_res, result);
    }
  }
}

int mult_possible(s21_decimal value) {
  int possible = 0;
  int bit_29 = s21_get_bit(value, 93);
  int bit_30 = s21_get_bit(value, 94);
  int bit_31 = s21_get_bit(value, 95);
  if (bit_29 == 0 && bit_30 == 0 && bit_31 == 0) {
    s21_decimal mult_by_8 = value;
    offset_left(&mult_by_8, 1);
    offset_left(&mult_by_8, 1);
    offset_left(&mult_by_8, 1);
    s21_decimal mult_by_2 = value;
    offset_left(&mult_by_2, 1);
    s21_decimal result = {{0, 0, 0, 0}};
    if (s21_bit_add(mult_by_8, mult_by_2, &result) == 0) {
      possible = 1;
    }
  }
  return possible;
}

void set_bit(unsigned int *number, int bit_position, int bit) {
  unsigned int mask = 1;
  mask <<= bit_position;
  if (bit == 0) {
    mask = ~mask;
    *number &= mask;
  }
  if (bit == 1) {
    *number |= mask;
  }
}

unsigned int div_by_10(s21_decimal *value) {
  unsigned int buffer = 0;
  int exp = s21_get_scale(*value);
  s21_decimal result = {{0, 0, 0, 0}};

  int last_bit = s21_get_last_bit(*value);

  for (int i = 0; i < last_bit + 2; i++) {
    if (buffer >= 10) {
      offset_left(&result, 1);
      set_bit(&result.bits[0], 0, 1);
      buffer = buffer - 10u;
      int new_bit = s21_get_bit(*value, last_bit - i);
      buffer = buffer << 1;
      set_bit(&buffer, 0, new_bit);
    } else {
      offset_left(&result, 1);
      set_bit(&result.bits[0], 0, 0);
      int new_bit = s21_get_bit(*value, last_bit - i);
      buffer = buffer << 1;
      set_bit(&buffer, 0, new_bit);
    }
  }
  buffer = buffer >> 1;
  *value = result;
  s21_set_scale(value, exp);

  return buffer;
}

void scale_equalize(s21_decimal *value_1, s21_decimal *value_2) {
  int exp_1 = s21_get_scale(*value_1);
  int exp_2 = s21_get_scale(*value_2);
  int delta = exp_1 - exp_2;
  int sign_1 = 1;
  if (delta < 0) {
    delta = -delta;
  }
  if (delta != 0) {
    s21_decimal *big, *small;
    if (exp_1 > exp_2) {
      big = value_1;
      small = value_2;
    } else {
      big = value_2;
      small = value_1;
    }
    for (int i = 0; i < delta; i++) {
      if (mult_possible(*small) == 1) {
        int current_scale = s21_get_scale(*small);
        mult_by_10(small);
        s21_set_scale(small, current_scale + 1);
      } else {
        int current_scale = s21_get_scale(*big);
        if (i == delta - 1) {
          unsigned int last = big->bits[0] % 10;
          unsigned int penultimate = big->bits[0] % 100 - last;
          int big_sign = s21_get_sign(*big);

          div_by_10(big);
          s21_set_scale(big, current_scale - 1);

          if (last == 5 && (penultimate % 2) == 1) {
            s21_decimal result = {{0, 0, 0, 0}};
            if (big_sign == 0) {
              s21_decimal one = {{1, 0, 0, 0}};
              s21_bit_add(*big, one, &result);
              *big = result;
            } else {
              s21_decimal one = {{1, 0, 0, 0}};
              s21_set_sign(&one, sign_1);
              s21_bit_add(*big, one, &result);
              *big = result;
            }
          }
        } else {
          div_by_10(big);
          s21_set_scale(big, current_scale - 1);
        }
      }
    }
  }
}

int s21_get_first_bit(s21_decimal value) {
  int i = -1;
  for (i = 95; i >= 0; i--) {
    if (s21_get_bit(value, i)) break;
  }
  return i;
}

void mult_by_10(s21_decimal *value) {
  s21_decimal mult_by_8 = *value;
  offset_left(&mult_by_8, 1);
  offset_left(&mult_by_8, 1);
  offset_left(&mult_by_8, 1);
  s21_decimal mult_by_2 = *value;
  offset_left(&mult_by_2, 1);
  s21_bit_add(mult_by_8, mult_by_2, value);
}

void clean_long_decimal(s21_long_decimal *decimal) {
  decimal->bits[0] = 0;
  decimal->bits[1] = 0;
  decimal->bits[2] = 0;
  decimal->bits[3] = 0;
  decimal->bits[4] = 0;
  decimal->bits[5] = 0;
  decimal->bits[6] = 0;
  decimal->bits[7] = 0;
}

// копирование в long decimal
void from_decimal_to_long(s21_decimal value_1, s21_long_decimal *value_2) {
  value_2->bits[0] = value_1.bits[0];
  value_2->bits[1] = value_1.bits[1];
  value_2->bits[2] = value_1.bits[2];
}

// копирование из long decimal
void from_long_to_decimal(s21_long_decimal value_1, s21_decimal *value_2) {
  value_2->bits[0] = value_1.bits[0];
  value_2->bits[1] = value_1.bits[1];
  value_2->bits[2] = value_1.bits[2];
}

// поставить нужный бит в 1 или 0 в структуре long decimal
void set_bit_long_decimal(s21_long_decimal *decimal, int index, int new_bit) {
  int mask = 1u << s21_get_bit_array_index(index);
  if (new_bit == 1)
    decimal->bits[s21_get_bit_array(index)] |= mask;
  else
    decimal->bits[s21_get_bit_array(index)] &= ~mask;
}

// посмотреть, 0 или 1 стоит под конкретным индексом в структуре long decimal
int get_bit_long_decimal(s21_long_decimal decimal, int index) {
  int mask = 1u << s21_get_bit_array_index(index);
  return (decimal.bits[s21_get_bit_array(index)] & mask) != 0;
}

// смещение мантиссы влево в long decimal
// return не ноль если переполнение
int offset_left_long_decimal(s21_long_decimal *decimal, int offset) {
  int res = 0;
  int byte[8] = {0};
  for (int i = 0; i < offset; i++) {
    for (int j = 0; j < 7; j++) {
      byte[j] = get_bit_long_decimal(*decimal, (32 * i) + 31);
    }
    for (int j = 0; j > 0 && res == 0; j--) {
      res = get_bit_long_decimal(*decimal, 255);
      decimal->bits[j] <<= 1;
      set_bit_long_decimal(decimal, j * 32, byte[j - 1]);
    }
    decimal->bits[0] <<= 1;
  }
  return res;
}

// смещение мантиссы вправо в long decimal
void offset_right_long_decimal(s21_long_decimal *decimal, int offset) {
  int byte[7] = {0};
  for (int i = 0; i < offset; i++) {
    for (int j = 0; j < 7; j++) {
      byte[j] = get_bit_long_decimal(*decimal, (i + 1) * 32);
    }
    for (int j = 0; j < 7; j++) {
      decimal->bits[j] >>= 1;
      set_bit_long_decimal(decimal, (32 * i) + 31, byte[j]);
    }
    decimal->bits[7] >>= 1;
  }
}

// сложение long decimal
void add_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2,
                      s21_long_decimal *result) {
  int res = 0;
  int mem = 0;
  for (int i = 0; i <= 255; i++) {
    res = get_bit_long_decimal(value_1, i) + get_bit_long_decimal(value_2, i) +
          mem;
    mem = res / 2;
    set_bit_long_decimal(result, i, res % 2);
  }
}

// вычитание long decimal
void sub_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2,
                      s21_long_decimal *result) {
  int res = 0;
  int mem = 0;
  for (int i = 0; i <= 255; i++) {
    res = get_bit_long_decimal(value_1, i) - get_bit_long_decimal(value_2, i) -
          mem;
    mem = res < 0;
    res = abs(res);
    set_bit_long_decimal(result, i, res % 2);
  }
}

// умножение двух long decimal
// return не ноль если переполнение
int mul_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2,
                     s21_long_decimal *result) {
  int res = 0;
  int j = 0;
  clean_long_decimal(result);
  for (int i = 0; i <= 255 && res == 0; i++) {
    if (get_bit_long_decimal(value_2, i) == 1) {
      res = offset_left_long_decimal(&value_1, i - j);
      add_long_decimal(value_1, *result, result);
      j = i;
    }
  }
  return res;
}

// увеличение скейла на n и домножение мантиссы
void increase_scale_long_decimal(s21_long_decimal *decimal, int n) {
  s21_long_decimal ten;
  s21_long_decimal tmp;
  clean_long_decimal(&ten);
  clean_long_decimal(&tmp);
  ten.bits[0] = 10;
  for (int i = 0; i < n; i++) {
    mul_long_decimal(*decimal, ten, &tmp);  // умножение long decimal на 10
    *decimal = tmp;
    clean_long_decimal(&tmp);
  }
}

// больше ли перовое чем второе
// 0 если меньше, 1 если больше
int is_greater_long_decimal(s21_long_decimal value_1,
                            s21_long_decimal value_2) {
  int result = 0;
  int out = 0;
  for (int i = 7; i >= 0 && !result && !out; i--) {
    if (value_1.bits[i] || value_2.bits[i]) {
      if (value_1.bits[i] > value_2.bits[i]) {
        result = 1;
      }
      if (value_1.bits[i] != value_2.bits[i]) out = 1;
    }
  }
  return result;
}

// больше или равно ли перовое чем второе
// 0 если меньше, 1 если больше или равно
int is_greater_or_equal_long_decimal(s21_long_decimal value_1,
                                     s21_long_decimal value_2) {
  int result = 0;
  int out = 0;
  for (int i = 7; i >= 0 && !out && !result; i--) {
    if (value_1.bits[i] != 0 || value_2.bits[i] != 0) {
      if (value_1.bits[i] >= value_2.bits[i]) {
        result = 1;
      }
      out = 1;
    }
  }
  return result;
}

// уравнивание long decimal
int equalization_long_decimal(s21_long_decimal *value_1,
                              s21_long_decimal *value_2) {
  int scale = 0;
  while (is_greater_long_decimal(*value_2, *value_1)) {
    increase_scale_long_decimal(value_1, 1);
    scale++;
  }
  while (is_greater_or_equal_long_decimal(*value_1, *value_2)) {
    offset_left_long_decimal(value_2, 1);
  }
  offset_right_long_decimal(value_2, 1);
  return scale;
}

// равени ли long decimal нулю
// 0 если равен
int is_zero_long_decimal(s21_long_decimal v) {
  return v.bits[0] + v.bits[1] + v.bits[2] + v.bits[3] + v.bits[4] + v.bits[5] +
         v.bits[6] + v.bits[7];
}

// равени ли decimal нулю
// 0 если равен
int is_zero_decimal(s21_decimal v) { return v.bits[0] + v.bits[1] + v.bits[2]; }

// наибольший бит в long decimal
void find_highest_bit_long_decimal(s21_long_decimal value_1,
                                   s21_long_decimal value_2, int *b1, int *b2) {
  for (int i = 255; i >= 0 && (!(*b1) || !(*b2)); i--) {
    if (*b1 == 0 && get_bit_long_decimal(value_1, i)) {
      *b1 = i;
    }
    if (*b2 == 0 && get_bit_long_decimal(value_2, i)) {
      *b2 = i;
    }
  }
}

// деление двух long decimal
// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0
int div_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2,
                     s21_long_decimal *result) {
  int b_1 = 0, b_2 = 0, bit_2 = 0, scale = 0, diff = 0, save_scale = 0;
  s21_long_decimal tmp = {0};
  clean_long_decimal(result);
  find_highest_bit_long_decimal(value_1, value_2, &b_1, &b_2);
  bit_2 = b_2;
  for (int i = 0; i < 96 && is_zero_long_decimal(value_1);) {
    if (i > 0) {
      offset_left_long_decimal(&value_2, 1);
      increase_scale_long_decimal(result, 1);
      increase_scale_long_decimal(&value_1, 1);
      save_scale++;
    }
    scale = equalization_long_decimal(&value_1, &value_2);
    save_scale += scale;
    b_1 = b_2 = 0;
    find_highest_bit_long_decimal(value_1, value_2, &b_1, &b_2);
    diff = b_2 - bit_2;
    if (diff < 0) diff = 0;
    for (; diff >= 0 && is_zero_long_decimal(value_1);) {
      if (is_greater_long_decimal(value_2, value_1)) {
        set_bit_long_decimal(&tmp, 0, 0);
      } else {
        sub_long_decimal(value_1, value_2, &value_1);
        set_bit_long_decimal(&tmp, 0, 1);
      }
      i++;
      diff--;
      if (diff >= 0) offset_right_long_decimal(&value_2, 1);
      offset_left_long_decimal(&tmp, 1);
    }
    if (diff >= 0) offset_left_long_decimal(&tmp, diff + 1);
    offset_right_long_decimal(&tmp, 1);
    add_long_decimal(*result, tmp, result);
    clean_long_decimal(&tmp);
  }
  return save_scale;
}

// приведение к виду, который поместится в децимал
int shortening(s21_long_decimal *decimal, int scale) {
  int e = 0;
  s21_long_decimal ten;
  s21_long_decimal tmp;
  clean_long_decimal(&ten);
  clean_long_decimal(&tmp);
  ten.bits[0] = 10;
  while ((decimal->bits[3] + decimal->bits[4] + decimal->bits[5] +
          decimal->bits[6] + decimal->bits[7]) != 0 &&
         scale > 0) {
    if (scale == 1 && decimal->bits[3]) {
      e = 1;
    }
    div_long_decimal(*decimal, ten, &tmp);  // деление long decimal на 10
    *decimal = tmp;
    clean_long_decimal(&tmp);
    scale--;  // уменьшение степени
  }
  if (e == 1 && get_bit_long_decimal(*decimal, 0) == 1) {
    set_bit_long_decimal(decimal, 0, 0);
  }
  if ((decimal->bits[3] + decimal->bits[4] + decimal->bits[5] +
       decimal->bits[6] + decimal->bits[7]) != 0) {
    scale = -1;
  }
  return scale;
}

// определение знака для деления и умножения
// 0 +
// 1 -
int sign_dm(s21_decimal value_1, s21_decimal value_2) {
  return s21_get_sign(value_1) ^ s21_get_sign(value_2);
}
