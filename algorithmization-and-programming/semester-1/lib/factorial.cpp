//
// Created by daniil_stepanenko on 15.10.2021.
//

#include "../include/factorial.h"

template <typename T>
FactorialCache<T>::FactorialCache() {
    this->cache.push_back(1);
    this->cache.push_back(1);
    this->cache.push_back(2);
}

template <typename T>
T FactorialCache<T>::factorial(int x) {
    if (this->cache.size() <= x) {
        this->cache.push_back(this->calculate_factorial(x));
    }

    return this->cache.at(x);
}

template <typename T>
T FactorialCache<T>::factorial_sum(int n) {
    int sum = this->factorial(n);

    for (int i = 1; i < n; i++) {
        sum += this->cache.at(i);
    }

    return sum;
}

template <typename T>
T FactorialCache<T>::calculate_factorial(int x) {
    return x*this->factorial(x-1);
}
