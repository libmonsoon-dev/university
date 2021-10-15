//
// Created by daniil_stepanenko on 15.10.2021.
//

#include "factorial.h"


FactorialCache::FactorialCache() {
    this->cache.push_back(1);
    this->cache.push_back(1);
    this->cache.push_back(2);
}

int FactorialCache::factorial(int i) {
    if (this->cache.size() <= i) {
        this->cache.push_back(this->calculate_factorial(i));
    }

    return this->cache.at(i);
}

int FactorialCache::calculate_factorial(int i) {
    return i*this->factorial(i-1);
}

