GCC = gcc -Wall -Werror -Wextra -std=c11
TESTDIR = tests/
C_FILES = $(wildcard s21_*.c)
O_FILES = $(patsubst %c,%o,$(C_FILES))
TEST_C = $(wildcard $(TESTDIR)check_s21*.c)
TESTOBJS = $(patsubst %c,%o,$(TEST_C))
TESTMAIN = $(TESTDIR)check_run_tests.c
CFLAGS = -Wall -Werror -Wextra -g
OS = $(shell uname)
COVERAGE = --coverage


ifeq ($(OS), Darwin)
	TEST_LIBS = -lcheck -lgcov
	LEAKS = leaks -atExit -- ./test
else
	TEST_LIBS = -lcheck -lsubunit -pthread -lm -lrt -lgcov
	LEAKS = valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test 
endif



all: clean gcov_report

main:
	$(GCC) *.c

s21_math.a:
	$(GCC) -c s21_*.c
	ar rc s21_math.a s21_*.o
	ranlib s21_math.a

s21_math_test.a: $(O_FILES)
	ar rc  s21_math.a s21_*.o
	ranlib s21_math.a

test: s21_math_test.a 
	$(GCC) check_run_tests.c check_s21*.c s21_math.a -o test $(TEST_LIBS)
	./test
	
%.o: %.c
	$(GCC) $(CFLAGS) $(COVERAGE) -c $(<) -o $(@) $(LIBS)

gcov_report: test 
	lcov -t "Core" -o s21_test.info -c -d . 
	genhtml -o report s21_test.info 
	open ./report/index.html

check:

	clang-format -n --style=Google *.c *.h
	
tocheck:
	clang-format -i --style=Google *.c *.h

install:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
	brew install gcovr
	
clean:
	rm -rf *.a *.o
	rm -rf $(TESTDIR)*.o
	rm -rf $(TESTDIR)*.a
	rm -rf $(TESTDIR)*.gcno $(TESTDIR)*.gcda *.gcno *.gcda
	rm -rf *.info
	rm -rf report
	rm -rf ./test
	rm -rf test.dSYM
