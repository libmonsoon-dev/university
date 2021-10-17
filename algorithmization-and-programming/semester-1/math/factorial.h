//
// Created by daniil_stepanenko on 15.10.2021.
//

#ifndef UNIVERSITY_FACTORIAL_H
#define UNIVERSITY_FACTORIAL_H

#include <vector>

template <typename T>
class FactorialCache {
public:
    FactorialCache();
    T factorial(int x);
    T factorial_sum(int n);

private:
    std::vector<T> cache;
    T calculate_factorial(int x);
};

template class FactorialCache<int>;

#endif //UNIVERSITY_FACTORIAL_H
