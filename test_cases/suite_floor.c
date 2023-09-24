#include "../s21_test_decimal.h"

START_TEST(s21_floor_1) {
  s21_decimal src;
  src.bits[0] = 0;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_decimal result;
  result.bits[0] = 0;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_floor(src, &src);
  ck_assert_float_eq(src.bits[0], result.bits[0]);
  ck_assert_float_eq(src.bits[1], result.bits[1]);
  ck_assert_float_eq(src.bits[2], result.bits[2]);
  ck_assert_float_eq(src.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal src;
  src.bits[0] = 1;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_decimal result;
  result.bits[0] = 1;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_floor(src, &src);
  ck_assert_float_eq(src.bits[0], result.bits[0]);
  ck_assert_float_eq(src.bits[1], result.bits[1]);
  ck_assert_float_eq(src.bits[2], result.bits[2]);
  ck_assert_float_eq(src.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal src;
  src.bits[0] = 123;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_set_scale(&src, 1);
  s21_decimal result;
  result.bits[0] = 12;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_floor(src, &src);
  ck_assert_float_eq(src.bits[0], result.bits[0]);
  ck_assert_float_eq(src.bits[1], result.bits[1]);
  ck_assert_float_eq(src.bits[2], result.bits[2]);
  ck_assert_float_eq(src.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal src;
  src.bits[0] = 123;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147483648;
  s21_set_scale(&src, 1);
  s21_decimal result;
  result.bits[0] = 13;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 2147483648;
  s21_floor(src, &src);
  ck_assert_float_eq(src.bits[0], result.bits[0]);
  ck_assert_float_eq(src.bits[1], result.bits[1]);
  ck_assert_float_eq(src.bits[2], result.bits[2]);
  ck_assert_float_eq(src.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal src;
  src.bits[0] = 0b01010101001110101110101110110001;
  src.bits[1] = 0b00001101101101001101101001011111;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000100100000000000000000;
  s21_floor(src, &src);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(src.bits[0], result.bits[0]);
  ck_assert_float_eq(src.bits[1], result.bits[1]);
  ck_assert_float_eq(src.bits[2], result.bits[2]);
  ck_assert_float_eq(src.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_10) {
  s21_decimal src;
  src.bits[0] = 0b01010101001110101110101110110001;
  src.bits[1] = 0b00001101101101001101101001011111;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000100100000000000000000;
  s21_floor(src, &src);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(src.bits[0], result.bits[0]);
  ck_assert_float_eq(src.bits[1], result.bits[1]);
  ck_assert_float_eq(src.bits[2], result.bits[2]);
  ck_assert_float_eq(src.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_floor() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_floor");
  tc = tcase_create("case_floor");
  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_9);
  tcase_add_test(tc, s21_floor_10);

  suite_add_tcase(s, tc);

  return s;
}
