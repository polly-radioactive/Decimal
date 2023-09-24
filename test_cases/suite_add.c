#include "../s21_test_decimal.h"

START_TEST(simple_add_1) {
  s21_decimal val1 = {{46521, 3, 0, 0}};
  s21_decimal val2 = {{34521, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 81042);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(simple_add_2) {
  s21_decimal val1 = {{0xFFFFFFFF, 3, 0, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 4);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(diff_scales_add_1) {
  s21_decimal val1 = {{56, 0, 0, 196608}};
  s21_decimal val2 = {{13, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 13056);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 196608);
}
END_TEST

START_TEST(negative_add) {
  s21_decimal val1 = {{56, 4294967295, 0, 2147483648}};
  s21_decimal val2 = {{69, 1, 0, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 125);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1);
  ck_assert_int_eq(res.bits[3], 2147483648);
}
END_TEST

START_TEST(error_1) {
  s21_decimal val1 = {{4294967295, 4294967295, 4294967295, 2147483648}};
  s21_decimal val2 = {{429, 0, 0, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(error_2) {
  s21_decimal val1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal val2 = {{405, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(negative_1) {
  s21_decimal val1 = {{5674, 4222, 1000, 0}};
  s21_decimal val2 = {{45, 211, 98, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 5629);
  ck_assert_int_eq(res.bits[1], 4011);
  ck_assert_int_eq(res.bits[2], 902);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(test_0) {
  s21_decimal val1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 0x00000000);
  ck_assert_int_eq(res.bits[1], 0x00000000);
  ck_assert_int_eq(res.bits[2], 0x00000000);
  ck_assert_int_eq(res.bits[3], 0x00000000);
}
END_TEST

START_TEST(test_1) {
  s21_decimal val1 = {{0x00000183, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal val2 = {{0x00004DA6, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 0x00004F29);
  ck_assert_int_eq(res.bits[1], 0x00000000);
  ck_assert_int_eq(res.bits[2], 0x00000000);
  ck_assert_int_eq(res.bits[3], 0x00020000);
}
END_TEST

START_TEST(test_2) {
  s21_decimal val1 = {{0x77D5E3AA, 0x0000011C, 0x00000000, 0x00060000}};
  s21_decimal val2 = {{0x00212155, 0x00000000, 0x00000000, 0x00070000}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_add(val1, val2, &res);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 0xAE7C05F9);
  ck_assert_int_eq(res.bits[1], 0x00000B1C);
  ck_assert_int_eq(res.bits[2], 0x00000000);
  ck_assert_int_eq(res.bits[3], 0x00070000);
}
END_TEST

Suite *suite_add(void) {
  Suite *s = suite_create("Checking add...");
  TCase *tcase = tcase_create("add_tc");

  tcase_add_test(tcase, simple_add_1);
  tcase_add_test(tcase, simple_add_2);
  tcase_add_test(tcase, negative_add);
  tcase_add_test(tcase, error_1);
  tcase_add_test(tcase, error_2);
  tcase_add_test(tcase, negative_1);
  tcase_add_test(tcase, diff_scales_add_1);
  tcase_add_test(tcase, test_0);
  tcase_add_test(tcase, test_1);
  tcase_add_test(tcase, test_2);
  suite_add_tcase(s, tcase);

  return s;
}
