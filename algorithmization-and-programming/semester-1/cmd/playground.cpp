//
// Created by daniil_stepanenko on 16.10.2021.
//

#include <stdlib.h>

#include "../include/matrix.h"
#include "../include/io_utils.h"

int main() {
    const int rows = 2;
    const int columns = 3;

    auto matrix = new Matrix<int>(rows, columns);

    read_matrix(matrix);
    print_matrix(matrix);

    delete matrix;
    return EXIT_SUCCESS;
}
