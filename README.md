# s21_matrix

A C library for matrix operations.

## Features

- Matrix creation and deletion
- Matrix comparison
- Matrix addition and subtraction
- Scalar multiplication
- Matrix multiplication
- Transposition
- Determinant calculation
- Calculation of matrix of cofactors
- Inverse matrix computation

## Matrix Structure

```c
typedef struct matrix_struct {
    double **matrix;
    int rows;
    int columns;
} matrix_t;
```

## Build and Test

To build the library and run tests, use the Makefile:

```sh
cd src
make all        # Build the library
make test       # Run tests
make gcov_report # Generate coverage report
make clean      # Clean build files
```

## Usage Example

```c
#include "s21_matrix.h"

int main() {
    matrix_t A, B, result;
    s21_create_matrix(2, 2, &A);
    s21_create_matrix(2, 2, &B);
    // ... fill matrices ...
    s21_sum_matrix(&A, &B, &result);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    return 0;
}
```

## Tests

Tests are implemented using the Check library and cover all main functions. To check for memory leaks:

```sh
make test_valgrind
```

## Highlights

- C11 standard compliant
- Google Style
- Static library (s21_matrix.a)
- Full unit test coverage
- Efficient memory allocation for matrices 