#include "../s21_test_decimal.h"

START_TEST(s21_truncate_1) {
  s21_decimal src;
  src.bits[0] = 211;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_set_scale(&src, 1);
  s21_decimal result;
  result.bits[0] = 21;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_decimal res1;
  s21_truncate(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal src;
  src.bits[0] = 165;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147483648;
  s21_set_scale(&src, 1);
  s21_decimal result;
  result.bits[0] = 16;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 2147483648;
  s21_decimal res1;
  s21_truncate(src, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal src;
  src.bits[0] = 2147443413;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_set_scale(&src, 7);
  float num = 214.7443413;
  s21_decimal result;
  result.bits[0] = (int)trunc(num);
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_decimal res1;
  s21_truncate(src, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal src;
  src.bits[0] = 1000000;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_set_scale(&src, 6);
  s21_decimal result;
  s21_truncate(src, &result);
  s21_decimal res1;
  res1.bits[0] = 1;
  res1.bits[1] = 0;
  res1.bits[2] = 0;
  res1.bits[3] = 0;
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncate_8) {
  s21_decimal src;

  src.bits[0] = -1;
  src.bits[1] = -1;
  src.bits[2] = -1;
  src.bits[3] = 0;
  s21_set_scale(&src, 28);
  s21_decimal result;
  result.bits[0] = 7;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  s21_decimal res1;
  s21_truncate(src, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_9) {
  s21_decimal src = {{123, 123, 0, 0}};
  s21_decimal res;
  s21_truncate(src, &res);
  ck_assert_int_eq(res.bits[0], 123);
  ck_assert_int_eq(res.bits[1], 123);
}
END_TEST

Suite *suite_truncate() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_truncate");
  tc = tcase_create("case_truncate");
  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_4);
  tcase_add_test(tc, s21_truncate_7);
  tcase_add_test(tc, s21_truncate_8);
  tcase_add_test(tc, s21_truncate_9);
  suite_add_tcase(s, tc);

  return (s);
}
