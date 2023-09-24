#include "../s21_test_decimal.h"

START_TEST(simple_sub_1) {
  s21_decimal val1 = {{80, 6643, 0, 0}};
  s21_decimal val2 = {{56, 6543, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 24);
  ck_assert_int_eq(res.bits[1], 100);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(simple_sub_2) {
  s21_decimal val1 = {{56, 6043, 0, 0}};
  s21_decimal val2 = {{80, 6543, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 24);
  ck_assert_int_eq(res.bits[1], 500);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 2147483648);
}
END_TEST

START_TEST(sub_minus_minus_1) {
  s21_decimal val1 = {{20, 2, 0, 2147483648}};
  s21_decimal val2 = {{80, 0, 0, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 4294967236);
  ck_assert_int_eq(res.bits[1], 1);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 2147483648);
}
END_TEST

START_TEST(sub_minus_plus_1) {
  s21_decimal val1 = {{175, 0, 0, 2147483648}};
  s21_decimal val2 = {{60, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 235);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 2147483648);
}
END_TEST

START_TEST(sub_minus_plus_2) {
  s21_decimal val1 = {{60, 0, 0, 2147483648}};
  s21_decimal val2 = {{1000, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 1060);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 2147483648);
}
END_TEST

START_TEST(sub_plus_minus_1) {
  s21_decimal val1 = {{65, 1, 0, 0}};
  s21_decimal val2 = {{42, 5, 0, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 107);
  ck_assert_int_eq(res.bits[1], 6);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(sub_plus_minus_2) {
  s21_decimal val1 = {{65, 1234, 0, 0}};
  s21_decimal val2 = {{423, 5, 2, 2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 488);
  ck_assert_int_eq(res.bits[1], 1239);
  ck_assert_int_eq(res.bits[2], 2);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(error) {
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 2147483648}};
  s21_decimal val2 = {{4, 4, 12, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(scale_1) {
  s21_decimal val1 = {{6, 8, 0, 196608}};   // 3 cтепень
  s21_decimal val2 = {{12, 2, 0, 524288}};  // 8 степень
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 599988);
  ck_assert_int_eq(res.bits[1], 799998);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 524288);
}
END_TEST

START_TEST(scale_2) {
  s21_decimal val1 = {{450, 0, 0, 983040}};  // 15 степень
  s21_decimal val2 = {{3, 0, 0, 131072}};    // 2 степень
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 3948404286);
  ck_assert_int_eq(res.bits[1], 6984);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 2148466688);
}
END_TEST

START_TEST(test_0) {
  s21_decimal val1 = {{0x00000183, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal val2 = {{0x00004DA6, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal res = {{0, 0, 0, 0}};
  int result = s21_sub(val1, val2, &res);

  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.bits[0], 0x00004C23);
  ck_assert_int_eq(res.bits[1], 0x00000000);
  ck_assert_int_eq(res.bits[2], 0x00000000);
  ck_assert_int_eq(res.bits[3], 0x80020000);
}
END_TEST

Suite *suite_sub() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_sub");
  tc = tcase_create("case_sub");

  tcase_add_test(tc, simple_sub_1);
  tcase_add_test(tc, simple_sub_2);
  tcase_add_test(tc, error);
  tcase_add_test(tc, sub_minus_minus_1);
  tcase_add_test(tc, sub_minus_plus_1);
  tcase_add_test(tc, sub_minus_plus_2);
  tcase_add_test(tc, sub_plus_minus_1);
  tcase_add_test(tc, sub_plus_minus_2);
  tcase_add_test(tc, scale_1);
  tcase_add_test(tc, scale_2);
  tcase_add_test(tc, test_0);
  suite_add_tcase(s, tc);

  return s;
}
