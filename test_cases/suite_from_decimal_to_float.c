#include "../s21_test_decimal.h"

START_TEST(from_decimal_to_float_1) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 1234567;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 3;
  s21_from_decimal_to_float(decimal, &result);
  ck_assert_float_eq_tol(result, 1234.567, 1e7);
}
END_TEST

START_TEST(from_decimal_to_float_2) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 0b11111111111111111111111111111111;
  decimal.bits[1] = 0b11111111111111111111111111111111;
  decimal.bits[2] = 0b11111111111111111111111111111111;
  decimal.bits[3] = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, 79228162514264337593543950336.0f);
}
END_TEST

START_TEST(from_decimal_to_float_3) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 457865;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 2147483648;
  s21_set_scale(&decimal, 3);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, -457.865);
}
END_TEST

START_TEST(from_decimal_to_float_4) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 1905;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 2147483648;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, -1905);
}
END_TEST

START_TEST(from_decimal_to_float_5) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 0xFFFFF;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, 1048575);
}
END_TEST

START_TEST(from_decimal_to_float_6) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 4364764;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 2147483648;
  s21_set_scale(&decimal, 8);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq_tol(result, -0.4364764, 1e7);
}
END_TEST

START_TEST(from_decimal_to_float_7) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = INT_MAX;
  decimal.bits[1] = INT_MAX;
  decimal.bits[2] = 0;
  decimal.bits[3] = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, pow(2, 63) - 1);
}
END_TEST

START_TEST(from_decimal_to_float_8) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 378492087;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 0;
  s21_set_scale(&decimal, 10);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, 0.0378492087);
}
END_TEST

START_TEST(from_decimal_to_float_9) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 2021;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 2147483648;
  s21_set_scale(&decimal, 28);
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, -2.021e-25);
}
END_TEST

START_TEST(from_decimal_to_float_10) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 0;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 2147483648;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, -0);
}
END_TEST

START_TEST(from_decimal_to_float_11) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 0b11111111111111111111111111111111;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 2147483648;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, -4294967295);
}
END_TEST

START_TEST(from_decimal_to_float_12) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = 0b11111111111111111111111111111111;
  decimal.bits[1] = 0;
  decimal.bits[2] = 0;
  decimal.bits[3] = 2147483648;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, -4294967295);
}
END_TEST

START_TEST(from_decimal_to_float_13) {
  s21_decimal decimal;
  float result = 0.0;
  decimal.bits[0] = INT_MAX;
  decimal.bits[1] = INT_MAX;
  decimal.bits[2] = INT_MAX;
  decimal.bits[3] = 0;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, &result), 0);
  ck_assert_float_eq(result, pow(2, 95) - 1);
}
END_TEST

START_TEST(from_decimal_to_float_14) {
  s21_decimal decimal;
  // 5476546
  float result = 0.0;
  float *copy_res = &result;
  decimal.bits[0] = 0b00000000010100111001000011000010;
  decimal.bits[1] = 0b00000000000000000000000000000000;
  decimal.bits[2] = 0b00000000000000000000000000000000;
  decimal.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, copy_res), 0);
  ck_assert_float_eq_tol(result, 54675.46, 1e7);
}
END_TEST

START_TEST(from_decimal_to_float_15) {
  s21_decimal decimal;
  // -0.46453
  float result = 0.0;
  float *copy_res = &result;
  decimal.bits[0] = 0b00000000000000001011010101110101;
  decimal.bits[1] = 0b00000000000000000000000000000000;
  decimal.bits[2] = 0b00000000000000000000000000000000;
  decimal.bits[3] = 0b10000000000001010000000000000000;
  ck_assert_int_eq(s21_from_decimal_to_float(decimal, copy_res), 0);
  ck_assert_float_eq(result, -0.46453);
}
END_TEST

START_TEST(from_decimal_to_float_16) {
  s21_decimal src1;
  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = -0.46453;
  src1.bits[0] = 0b00000000000000001011010101110101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -0.46453);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(from_decimal_to_float_17) {
  s21_decimal decimal;
  float src = 0;
  // 56789832
  float *src_copy = &src;
  decimal.bits[0] = 0b00000011011000101000101101001000;
  decimal.bits[1] = 0b00000000000000000000000000000000;
  decimal.bits[2] = 0b00000000000000000000000000000000;
  decimal.bits[3] = 0b00000000000110010000000000000000;  // 25
  s21_from_decimal_to_float(decimal, src_copy);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 0.0000000000000000056789832);
  snprintf(result, sizeof(result), "%f", src);
  ck_assert_str_eq(result,
                   var3str);  // равенство строк, чтобы длина строк в обоих
                              // массивах совпадала
}
END_TEST

START_TEST(from_decimal_to_float_18) {
  s21_decimal decimal;
  float src = 0;
  // 564.347384735
  float *src_copy = &src;
  decimal.bits[0] = 0b01100101101110011011001110011111;
  decimal.bits[1] = 0b00000000000000000000000010000011;
  decimal.bits[2] = 0b00000000000000000000000000000000;
  decimal.bits[3] = 0b00000000000010010000000000000000;  // 9
  s21_from_decimal_to_float(decimal, src_copy);
  ck_assert_float_eq_tol(
      src, 564.3473,
      1e7);  // равенство строк, чтобы длина строк в обоих массивах совпадала
}
END_TEST

START_TEST(from_decimal_to_float_19) {
  s21_decimal decimal;
  float src;
  float *src_copy = &src;
  // s21_decimal src1 = 5.5;

  decimal.bits[0] = 0b00000000000000000000000000110111;
  decimal.bits[1] = 0b00000000000000000000000000000000;
  decimal.bits[2] = 0b00000000000000000000000000000000;
  decimal.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(decimal, src_copy);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 5.5);
  snprintf(result, sizeof(result), "%f", src);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(from_decimal_to_float_20) {
  s21_decimal decimal;
  float src;
  float *src_copy = &src;
  // s21_decimal src1 = -5.5;

  decimal.bits[0] = 0b00000000000000000000000000110111;
  decimal.bits[1] = 0b00000000000000000000000000000000;
  decimal.bits[2] = 0b00000000000000000000000000000000;
  decimal.bits[3] = 0b10000000000000010000000000000000;
  s21_from_decimal_to_float(decimal, src_copy);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -5.5);
  snprintf(result, sizeof(result), "%f", src);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(from_decimal_to_float_21) {
  s21_decimal decimal;
  float src;
  float *src_copy = &src;
  // s21_decimal src1 = -5.67890765;

  decimal.bits[0] = 0b00100001110110010101001101001101;
  decimal.bits[1] = 0b00000000000000000000000000000000;
  decimal.bits[2] = 0b00000000000000000000000000000000;
  decimal.bits[3] = 0b10000000000010000000000000000000;
  s21_from_decimal_to_float(decimal, src_copy);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", -5.67890765);
  snprintf(result, sizeof(result), "%f", src);
  ck_assert_str_eq(result, var3str);
}
END_TEST

START_TEST(from_decimal_to_float_23) {
  s21_decimal src1;

  float src2;
  float *srcp = &src2;
  // s21_decimal src1 = 2.5086531268974139743;

  src1.bits[0] = 0b01100101111011101101100101011111;
  src1.bits[1] = 0b01011100001001010100001101000110;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  s21_from_decimal_to_float(src1, srcp);
  char var3str[1000];
  char result[1000];
  snprintf(var3str, sizeof(var3str), "%.6f", 2.50865312689741);
  snprintf(result, sizeof(result), "%f", src2);
  ck_assert_str_eq(result, var3str);
}
END_TEST

static s21_decimal src[] = {
    {{0x000026B9, 0x00000000, 0x00000000, 0x00030000}},  // 9.913
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
    {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  // -1
    {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // 2
    {{0x00000002, 0x00000000, 0x00000000, 0x80000000}},  // -2
    {{0x0000000F, 0x00000000, 0x00000000, 0x00010000}},  // 1.5
    {{0x0000000F, 0x00000000, 0x00000000, 0x80010000}},  // -1.5
    {{0x00000009, 0x00000000, 0x00000000, 0x00010000}},  // 0.9
    {{0x00000009, 0x00000000, 0x00000000, 0x80010000}},  // -0.9
    {{0x00000001, 0x00000000, 0x00000000, 0x80010000}},  // -0.1
    {{0x00000001, 0x00000000, 0x00000000, 0x00010000}},  // 0.1
    {{0x0000000B, 0x00000000, 0x00000000, 0x80010000}},  // -1.1
    {{0x0000000B, 0x00000000, 0x00000000, 0x00010000}},  // 1.1
    {{0x000031DD, 0x00000000, 0x00000000, 0x00030000}},  // 12.765
    {{0x00002F0D, 0x00000000, 0x00000000, 0x80030000}},  // -12.045
    {{0x0001869F, 0x00000000, 0x00000000, 0x00040000}},  // 9.9999
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x00000000}},  // 79228162514264337593543950335
    {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
      0x80000000}},  // -79228162514264337593543950335
    {{0x000000D3, 0x00007C45, 0x00007C57,
      0x80080000}},  // -5871783107468845.32076755
    {{0x003A6E50, 0x007F1483, 0x003215CF,
      0x00020000}},  // 605492791886648540813348.64
    {{0x00000000, 0x00000000, 0x00000000, 0x800A0000}},  // 0.0000000000
    {{0xF533512E, 0x0000004B, 0x00000000, 0x00060000}},  // 326236.328238
    {{0x51A337CD, 0x00000002, 0x00000000, 0x80040000}},  // -995958.5741
    {{0xDC425734, 0x01C068FA, 0x00000000, 0x00070000}},  // 12621621621.2821812
    {{0xCC133B70, 0x004D86D4, 0x00000000, 0x000B0000}},  // 218218.21721721712
    {{0x00000001, 0x00000000, 0x00000000,
      0x00140000}},  // 0.00000000000000000001
};

static float dst[] = {
    9.91300011f,
    0.f,
    1.f,
    -1.f,
    2.f,
    -2.f,
    1.5f,
    -1.5f,
    0.899999976f,
    -0.899999976f,
    -0.100000001f,
    0.100000001f,
    -1.10000002f,
    1.10000002f,
    12.7650003f,
    -12.0450001f,
    9.99989986f,
    79228162500000000000000000000.f,
    -79228162500000000000000000000.f,
    -5871782930000000.f,
    605492757000000000000000.f,
    0.f,
    326236.344f,
    -995958.563f,
    12621621200.f,
    218218.219f,
    9.99999968E-21f,
};

START_TEST(test) {
  for (size_t i = 0; i < sizeof(src) / sizeof(s21_decimal); ++i) {
    float tmp;
    int ret = s21_from_decimal_to_float(src[i], &tmp);
    if (tmp != dst[i]) {
      char buf1[512];
      char buf2[512];
      sprintf(buf1, "%.6E", tmp);
      sprintf(buf2, "%.6E", dst[i]);
      ck_assert(strcmp(buf1, buf2) == 0);
    } else {
      ck_assert_float_eq(tmp, dst[i]);
      ck_assert_int_eq(ret, 0);
    }
  }
}
END_TEST

// 4294967295
// 18446744073709551615
Suite *suite_from_decimal_to_float() {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_from_decimal_to_float");
  tc = tcase_create("case_from_decimal_to_float");
  tcase_add_test(tc, from_decimal_to_float_1);
  tcase_add_test(tc, from_decimal_to_float_2);
  tcase_add_test(tc, from_decimal_to_float_3);
  tcase_add_test(tc, from_decimal_to_float_4);
  tcase_add_test(tc, from_decimal_to_float_5);
  tcase_add_test(tc, from_decimal_to_float_6);
  tcase_add_test(tc, from_decimal_to_float_7);
  tcase_add_test(tc, from_decimal_to_float_8);
  tcase_add_test(tc, from_decimal_to_float_9);
  tcase_add_test(tc, from_decimal_to_float_10);
  tcase_add_test(tc, from_decimal_to_float_11);
  tcase_add_test(tc, from_decimal_to_float_12);
  tcase_add_test(tc, from_decimal_to_float_13);
  tcase_add_test(tc, from_decimal_to_float_14);
  tcase_add_test(tc, from_decimal_to_float_15);
  tcase_add_test(tc, from_decimal_to_float_16);
  tcase_add_test(tc, from_decimal_to_float_17);
  tcase_add_test(tc, from_decimal_to_float_18);
  tcase_add_test(tc, from_decimal_to_float_19);
  tcase_add_test(tc, from_decimal_to_float_20);
  tcase_add_test(tc, from_decimal_to_float_21);
  tcase_add_test(tc, from_decimal_to_float_23);
  suite_add_tcase(s, tc);
  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, test);
    suite_add_tcase(s, tc);
  }

  return s;
}