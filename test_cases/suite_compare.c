#include "../s21_test_decimal.h"

START_TEST(decimal_is_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&y, 1);
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_5) {
  s21_decimal x = {{0, 52, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  s21_set_sign(&x, 1);
  int res1 = s21_is_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_8) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  s21_set_bit(&x, 1, 3);
  s21_set_bit(&y, 1, 3);
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_9) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  s21_set_scale(&x, 3);
  s21_set_scale(&y, 3);
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_equal_10) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  int res1 = s21_is_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&y, 1);
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_5) {
  s21_decimal x = {{0, 52, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{1747, 0, 1, 0}};
  s21_set_sign(&x, 1);
  int res1 = s21_is_not_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_8) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  s21_set_bit(&x, 1, 3);
  s21_set_bit(&y, 1, 3);
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_9) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  s21_set_scale(&x, 3);
  s21_set_scale(&y, 3);
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_not_equal_10) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  int res1 = s21_is_not_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_1) {
  s21_decimal x = {{4294967295, 0, 0, 0}};
  s21_decimal y = {{0, 1, 0, 0}};
  int res1 = s21_is_less(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_5) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_less(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_less(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  int res1 = s21_is_less(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&y, 1);
  int res1 = s21_is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_9) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  int res1 = s21_is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_10) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  s21_set_bit(&x, 1, 127);
  int res1 = s21_is_less(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_or_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_5) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_less_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&y, 1);
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_9) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  s21_set_scale(&x, 3);
  s21_set_scale(&y, 3);
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_less_or_equal_10) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  int res1 = s21_is_less_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_greater(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_greater(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_greater(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_5) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_greater(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  int res1 = s21_is_greater(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&y, 1);
  int res1 = s21_is_greater(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_9) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  s21_set_scale(&x, 3);
  s21_set_scale(&y, 3);
  int res1 = s21_is_greater(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_10) {
  s21_decimal x = {0};
  s21_decimal y = {0};
  int res1 = s21_is_greater(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_or_equal_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_4) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_5) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_6) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  s21_set_sign(&y, 1);
  int res1 = s21_is_greater_or_equal(y, x);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_7) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&x, 1);
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 0;
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(decimal_is_greater_or_equal_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  s21_set_sign(&y, 1);
  int res1 = s21_is_greater_or_equal(x, y);
  int res2 = 1;
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *suite_compare() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_compare");
  tc = tcase_create("case_compare");
  tcase_add_test(tc, decimal_is_less_1);
  tcase_add_test(tc, decimal_is_less_2);
  tcase_add_test(tc, decimal_is_less_3);
  tcase_add_test(tc, decimal_is_less_4);
  tcase_add_test(tc, decimal_is_less_5);
  tcase_add_test(tc, decimal_is_less_6);
  tcase_add_test(tc, decimal_is_less_7);
  tcase_add_test(tc, decimal_is_less_8);
  tcase_add_test(tc, decimal_is_less_9);
  tcase_add_test(tc, decimal_is_less_10);
  tcase_add_test(tc, decimal_is_less_or_equal_1);
  tcase_add_test(tc, decimal_is_less_or_equal_2);
  tcase_add_test(tc, decimal_is_less_or_equal_4);
  tcase_add_test(tc, decimal_is_less_or_equal_5);
  tcase_add_test(tc, decimal_is_less_or_equal_6);
  tcase_add_test(tc, decimal_is_less_or_equal_7);
  tcase_add_test(tc, decimal_is_less_or_equal_8);
  tcase_add_test(tc, decimal_is_less_or_equal_9);
  tcase_add_test(tc, decimal_is_less_or_equal_10);
  tcase_add_test(tc, decimal_is_greater_1);
  tcase_add_test(tc, decimal_is_greater_2);
  tcase_add_test(tc, decimal_is_greater_3);
  tcase_add_test(tc, decimal_is_greater_4);
  tcase_add_test(tc, decimal_is_greater_5);
  tcase_add_test(tc, decimal_is_greater_6);
  tcase_add_test(tc, decimal_is_greater_7);
  tcase_add_test(tc, decimal_is_greater_8);
  tcase_add_test(tc, decimal_is_greater_9);
  tcase_add_test(tc, decimal_is_greater_10);
  tcase_add_test(tc, decimal_is_greater_or_equal_1);
  tcase_add_test(tc, decimal_is_greater_or_equal_2);
  tcase_add_test(tc, decimal_is_greater_or_equal_4);
  tcase_add_test(tc, decimal_is_greater_or_equal_5);
  tcase_add_test(tc, decimal_is_greater_or_equal_6);
  tcase_add_test(tc, decimal_is_greater_or_equal_7);
  tcase_add_test(tc, decimal_is_greater_or_equal_8);
  tcase_add_test(tc, decimal_is_equal_1);
  tcase_add_test(tc, decimal_is_equal_2);
  tcase_add_test(tc, decimal_is_equal_3);
  tcase_add_test(tc, decimal_is_equal_4);
  tcase_add_test(tc, decimal_is_equal_5);
  tcase_add_test(tc, decimal_is_equal_6);
  tcase_add_test(tc, decimal_is_equal_7);
  tcase_add_test(tc, decimal_is_equal_8);
  tcase_add_test(tc, decimal_is_equal_9);
  tcase_add_test(tc, decimal_is_equal_10);
  tcase_add_test(tc, decimal_is_not_equal_1);
  tcase_add_test(tc, decimal_is_not_equal_2);
  tcase_add_test(tc, decimal_is_not_equal_3);
  tcase_add_test(tc, decimal_is_not_equal_4);
  tcase_add_test(tc, decimal_is_not_equal_5);
  tcase_add_test(tc, decimal_is_not_equal_6);
  tcase_add_test(tc, decimal_is_not_equal_7);
  tcase_add_test(tc, decimal_is_not_equal_8);
  tcase_add_test(tc, decimal_is_not_equal_9);
  tcase_add_test(tc, decimal_is_not_equal_10);
  tcase_add_test(tc, decimal_is_less_or_equal_or_equal_3);
  tcase_add_test(tc, decimal_is_greater_or_equal_or_equal_3);

  suite_add_tcase(s, tc);
  return s;
}
