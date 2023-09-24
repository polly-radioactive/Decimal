CC=gcc
CFLAGS=-Wall -Wextra -Werror
CHECKFLAGS=-lcheck -lm -lpthread
GCOVFLAGS=-fprofile-arcs -ftest-coverage
DECIMALFILES = s21_decimal_funcs/*.c
OUT=exec
TESTFILES= s21_test_decimal.c test_cases/*.c

all: s21_decimal.a

tests: test gcov_report

gcov_report:
	$(CC) -o $(OUT) $(GCOVFLAGS) $(DECIMALFILES) $(TESTFILES) $(CHECKFLAGS)
	./$(OUT)
	lcov -capture --directory . --output-file main_coverage.info
	genhtml *.info -o ./gcov_report
	rm -rf *.gcda *.gcno *.info exec a.out

test:
	$(CC) $(DECIMALFILES) $(TESTFILES) $(CHECKFLAGS)

s21_decimal.a:
	$(CC) -c $(DECIMALFILES)
	clang-format -i *.[ch]
	ar -rc s21_decimal.a *.o
	rm -rf *.o
	
check:
	clang-format -style=Google -i $(DECIMALFILES) $(TESTFILES)
 
clean:
	rm -rf gcov_report tests/*.o ./a.out *.o *.gcda *.gcno *.info exec s21_decimal.a
