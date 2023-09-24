#include "../s21_test_decimal.h"

START_TEST(s21_round_1) {
  s21_decimal src;
  src.bits[0] = 165;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_set_scale(&src, 1);
  s21_decimal result;
  result.bits[0] = 17;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_decimal res1;
  s21_round(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal src;
  src.bits[0] = 165;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147483648;
  s21_set_scale(&src, 1);
  s21_decimal result;
  result.bits[0] = 17;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 2147483648;
  s21_decimal res1;
  s21_round(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal src;
  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_decimal result;
  result.bits[0] = INT_MAX;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_decimal res1;
  s21_round(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal src;
  src.bits[0] = 5;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147483648;
  s21_set_scale(&src, 1);
  s21_decimal result;
  result.bits[0] = 1;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 2147483648;
  s21_decimal res1;
  s21_round(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal src;
  src.bits[0] = 60;
  src.bits[1] = 60;
  src.bits[2] = 60;
  src.bits[3] = 0;
  s21_decimal result;
  result.bits[0] = 60;
  result.bits[1] = 60;
  result.bits[2] = 60;
  result.bits[3] = 0;
  s21_decimal res1;
  s21_round(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal src;
  src.bits[0] = 0;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0b11111111111111111111111111111111;
  s21_decimal res1;
  int err = s21_round(src, &res1);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal src;
  src.bits[0] = INT_MAX;
  src.bits[1] = INT_MAX;
  src.bits[2] = INT_MAX;
  src.bits[3] = 2147483648;
  s21_set_scale(&src, 21);
  s21_decimal res1;
  ck_assert_int_eq(s21_round(src, &res1), 0);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal src;
  src.bits[0] = 0;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147483648;
  s21_set_scale(&src, 10);
  s21_decimal result;
  result.bits[0] = 0;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 2147483648;
  s21_decimal res1 = {0};
  s21_round(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal src;
  src.bits[0] = 123456789;
  src.bits[1] = INT_MAX;
  src.bits[2] = -INT_MAX;
  src.bits[3] = 0;
  s21_decimal res1;
  s21_round(src, &res1);
  s21_decimal result;
  result.bits[0] = 123456789;
  result.bits[1] = INT_MAX;
  result.bits[2] = -INT_MAX;
  result.bits[3] = 0;
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal src;
  src.bits[0] = 100;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_set_scale(&src, 1);
  s21_decimal result;
  result.bits[0] = 10;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_decimal res1;
  s21_round(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal src;

  src.bits[0] = 0b10010111011100111001111111111111;
  src.bits[1] = 0b00111100000010000011000110001101;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b10000100100101110000000100100000;
  s21_decimal res1;
  int err = s21_round(src, &res1);

  ck_assert_float_eq(err, 1);
}
END_TEST

Suite *suite_round() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_round");
  tc = tcase_create("case_round");
  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_7);
  tcase_add_test(tc, s21_round_8);
  tcase_add_test(tc, s21_round_11);
  tcase_add_test(tc, s21_round_12);
  tcase_add_test(tc, s21_round_13);

  suite_add_tcase(s, tc);

  return s;
}
