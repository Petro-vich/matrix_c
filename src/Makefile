CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LDFLAGS = -lcheck -lm -lsubunit
GCOV_FLAG = --coverage

TARGET = matrix.a

SRC = $(wildcard *.c)
AUX_SRC = $(wildcard aux_func/*.c)

OBJ_DIR = f_obj

SRC_OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
AUX_SRC_OBJ = $(AUX_SRC:aux_func/%.c=$(OBJ_DIR)/%.o)


CLEAN_LIST = $(OBJ_DIR)/*.o matrix.a coverage_report tests/test_matrix f_obj

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(TARGET)


matrix.a: $(SRC_OBJ) $(AUX_SRC_OBJ)
	@ar r matrix.a $(SRC_OBJ) $(AUX_SRC_OBJ)


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: aux_func/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@


test: matrix.a
	$(CC) -o tests/test_matrix tests/test_matrix.c -L -l matrix.a $(LDFLAGS)
	./tests/test_matrix

test_valgrind: matrix.a
	$(CC) -o tests/test_matrix tests/test_matrix.c -L -l matrix.a $(LDFLAGS)
	valgrind --leak-check=full --track-origins=yes ./tests/test_matrix 


gcov_report: 
	mkdir -p coverage_report
	mkdir -p coverage_report/gcda_gcno

	$(CC) -o tests/test_matrix  --coverage $(SRC) $(AUX_SRC) tests/test_matrix.c $(LDFLAGS)
	./tests/test_matrix
	lcov -t "Coverage Report" -c -d tests --output-file coverage_report/coverage.info
	genhtml coverage_report/coverage.info --output-directory coverage_report/
	xdg-open coverage_report/index.html
	mv tests/*.gcda tests/*gcno coverage_report/gcda_gcno
	
clang-format:
	clang-format -n *.c *.h aux_func/*.c aux_func/*.h tests/*.c


clean:
	rm -rf $(CLEAN_LIST)


re: clean all
