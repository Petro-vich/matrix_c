CC = gcc
CFLAGS = -Wall -Wextra 
LDFLAGS = -lcheck -lm -lsubunit 	

SRC = $(wildcard *.c)
SRC_OBJ = $(SRC:.c=.o)

TARGET = main


all: $(TARGET) start clang-format s21_matrix.a test


s21_matrix.a: $(SRC_OBJ)
	ar r s21_matrix.a s21_*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
test: s21_matrix.a
	$(CC) -o test_matrix tests/test_matrix.c -L -l s21_matrix.a $(LDFLAGS)
	valgrind --tool=memcheck --leak-check=yes ./test_matrix



$(TARGET): $(SRC_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

start: $(TARGET)
	valgrind --tool=memcheck --leak-check=yes ./main



gcov_report: 
	mkdir -p coverage_report
	$(CC) -o test_matrix  --coverage $(wildcard s21*.c) tests/test_matrix.c $(LDFLAGS)
	./test_matrix
	lcov -t "Coverage Report" -c -d . --output-file coverage_report/coverage.info
	genhtml coverage_report/coverage.info --output-directory coverage_report/
	xdg-open coverage_report/index.html
clang-format:
	clang-format -n *.c *.h
	
clean:
	rm -rf *.o main s21_matrix.a *.gcda *gcno test_matrix coverage_report

re: clean all


