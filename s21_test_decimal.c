#include "s21_test_decimal.h"

int main(void) {
  int total = 13;
  Suite *test_cases[13];
  test_cases[0] = suite_from_decimal_to_float();  // no failures
  test_cases[1] = suite_from_int_to_decimal();    // no failures
  test_cases[2] = suite_from_decimal_to_int();    // no failures

  test_cases[3] = suite_truncate();  // no failures
  test_cases[4] = suite_negate();    // no failures
  test_cases[5] = suite_floor();     // no failures
  test_cases[6] = suite_round();     // no failures

  test_cases[7] = suite_compare();  // no failures
  test_cases[8] = suite_from_float_to_decimal();

  test_cases[9] = suite_mul();
  test_cases[10] = suite_add();
  test_cases[11] = suite_sub();
  test_cases[12] = suite_div();

  for (int i = 0; i < total; i++) {
    SRunner *runner = srunner_create(test_cases[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }
}
