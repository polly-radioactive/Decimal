#include "../s21_test_decimal.h"

START_TEST(negate_1) {
  s21_decimal value = {0};
  s21_decimal result;
  ck_assert_int_eq(0, s21_negate(value, &result));
}
END_TEST

START_TEST(negate_2) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_3) {
  s21_decimal val = {{2, 0, 0, ~(-1 / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_4) {
  s21_decimal val = {{0, 0, 0, ~(-1 / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

Suite *suite_negate() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_negate");
  tc = tcase_create("case_negate");
  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  tcase_add_test(tc, negate_4);

  suite_add_tcase(s, tc);
  return s;
}