//
// Created by daniil_stepanenko on 11.01.2022.
//

template<typename T>
int count_digits(T x) {
    int n = 1;
    while ((x /= 10) > 0) { n++; }
    return n;
}

template int count_digits(int x);
