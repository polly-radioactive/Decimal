#include "../s21_test_decimal.h"

START_TEST(from_int_to_decimal_1) {
  int number = 2147483647;
  s21_decimal decimal = {0};
  ck_assert_int_eq(s21_from_int_to_decimal(number, &decimal), 0);
  ck_assert_int_eq(decimal.bits[0], 2147483647);
  ck_assert_int_eq(decimal.bits[1], 0);
  ck_assert_int_eq(decimal.bits[2], 0);
  ck_assert_int_eq(decimal.bits[3], 0);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  int number = -2147483648;
  s21_decimal decimal = {0};
  ck_assert_int_eq(s21_from_int_to_decimal(number, &decimal), 0);
  ck_assert_int_eq(decimal.bits[0], 2147483648);
  ck_assert_int_eq(decimal.bits[1], 0);
  ck_assert_int_eq(decimal.bits[2], 0);
  ck_assert_int_eq(decimal.bits[3], 2147483648);
}
END_TEST

START_TEST(from_int_to_decimal_3) {
  int number = 258;
  s21_decimal decimal = {0};
  ck_assert_int_eq(s21_from_int_to_decimal(number, &decimal), 0);
  ck_assert_int_eq(decimal.bits[0], 258);
  ck_assert_int_eq(decimal.bits[1], 0);
  ck_assert_int_eq(decimal.bits[2], 0);
  ck_assert_int_eq(decimal.bits[3], 0);
}
END_TEST

START_TEST(from_int_to_decimal_4) {
  int number = -258;
  s21_decimal decimal = {0};
  ck_assert_int_eq(s21_from_int_to_decimal(number, &decimal), 0);
  ck_assert_int_eq(decimal.bits[0], 258);
  ck_assert_int_eq(decimal.bits[1], 0);
  ck_assert_int_eq(decimal.bits[2], 0);
  ck_assert_int_eq(decimal.bits[3], 2147483648);
}
END_TEST

Suite *suite_from_int_to_decimal() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_int_to_decimal");
  tc = tcase_create("case_from_int_to_decimal");

  tcase_add_test(tc, from_int_to_decimal_1);
  tcase_add_test(tc, from_int_to_decimal_2);
  tcase_add_test(tc, from_int_to_decimal_3);
  tcase_add_test(tc, from_int_to_decimal_4);

  suite_add_tcase(s, tc);
  return s;
}