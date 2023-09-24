#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S21_NAN 0.0 / 0.0
static const float max_decimal = 79228162514264337593543950335.f;
#define INF 1.0 / 0.0

typedef struct {
  unsigned int bits[4];
} s21_decimal;

// структура long decimal
typedef struct {
  unsigned int bits[8];
} s21_long_decimal;

typedef enum { OK, CALCULATION_ERROR } auxillary_errors;

int s21_get_bit(s21_decimal decimal, int index);
int s21_get_bit_array(int index);
int s21_get_bit_array_index(int index);
void s21_set_bit(s21_decimal *decimal, int index, int new_bit);
s21_decimal s21_init_decimal();
int s21_get_sign(s21_decimal decimal);
void s21_set_sign(s21_decimal *decimal, int sign);
void s21_inverse_bit(s21_decimal *decimal, int index);
int s21_get_scale(s21_decimal decimal);
int s21_print_binary(unsigned int x);
s21_decimal *s21_set_scale(s21_decimal *decimal, int scale);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_divide_by_10(s21_decimal *decimal);
int s21_get_binary_exp(float src);
void s21_find_non_zero_bit(s21_decimal decimal, int *index);
int s21_is_correct_float(float src);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_is_decimal_correct(s21_decimal decimal);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void mult_by_10(s21_decimal *value);
void left_shift(s21_decimal *decimal);
void s21_abs_decimal(s21_decimal *value_1);
int offset_left(s21_decimal *decimal, int value_offset);
void clean(s21_decimal *d);
void mul_only_bits(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);

void scale_equalize(s21_decimal *value_1, s21_decimal *value_2);

int s21_bit_add(s21_decimal var1, s21_decimal var2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int sub_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_get_last_bit(s21_decimal decimal);
int add_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_get_first_bit(s21_decimal value);
int sum_mantissa(s21_decimal one, s21_decimal two, s21_decimal *result);
unsigned int div_by_10(s21_decimal *value);
int mult_possible(s21_decimal value);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void clean_long_decimal(s21_long_decimal *decimal);
void from_decimal_to_long(s21_decimal value_1, s21_long_decimal *value_2);
void from_long_to_decimal(s21_long_decimal value_1, s21_decimal *value_2);
void set_bit_long_decimal(s21_long_decimal *decimal, int index, int new_bit);
int get_bit_long_decimal(s21_long_decimal decimal, int index);
int offset_left_long_decimal(s21_long_decimal *decimal, int offset);
void offset_right_long_decimal(s21_long_decimal *decimal, int offset);
void add_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2,
                      s21_long_decimal *result);
void sub_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2,
                      s21_long_decimal *result);
int mul_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2,
                     s21_long_decimal *result);
void increase_scale_long_decimal(s21_long_decimal *decimal, int n);
int is_greater_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2);
int is_greater_or_equal_long_decimal(s21_long_decimal value_1,
                                     s21_long_decimal value_2);
int equalization_long_decimal(s21_long_decimal *value_1,
                              s21_long_decimal *value_2);
int is_zero_long_decimal(s21_long_decimal v);
void find_highest_bit_long_decimal(s21_long_decimal value_1,
                                   s21_long_decimal value_2, int *b1, int *b2);
int div_long_decimal(s21_long_decimal value_1, s21_long_decimal value_2,
                     s21_long_decimal *result);
int shortening(s21_long_decimal *decimal, int scale);
int sign_dm(s21_decimal value_1, s21_decimal value_2);
int is_zero_decimal(s21_decimal v);
int bigger_scale(s21_decimal val1, s21_decimal val2);
int s21_handle_error(int error, int sign_1, int sign_2);
