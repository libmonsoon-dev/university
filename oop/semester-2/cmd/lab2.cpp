#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "../include/queue.h"

int main() {
    try {
        auto q = Queue();
        printf("Введите первый элемент очереди\n> ");
        std::cin >> q;
        std::cout << q;
        q << 1;
        std::cout << q;
        q << 2;
        std::cout << q;
        q << 3;
        std::cout << q;

        if (q != q) {
            throw "Очередь не равна сама себе";
        }

        int num;
        q >> &num;
        printf("%i\n", num);
        std::cout << q;

        q >> &num;
        printf("%i\n", num);
        std::cout << q;

        q >> &num;
        printf("%i\n", num);
        std::cout << q;

        q >> &num;
        printf("%i\n", num);
        std::cout << q;
    } catch (char const *msg) {
        printf("%s\n", msg);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
