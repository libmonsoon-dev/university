#include <cstdlib>
#include <cstdio>

#include "../include/sparse_matrix.h"

int main() {
    try {
        auto m = scan_sparse_matrix();

        m.Print();
        m.Transpose().Print();
        m.Add(m).Print();
        m.Multiply(2).Print();
        m.Multiply(m.Transpose()).Print();
    } catch (char const *msg) {
        printf("%s\n", msg);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
