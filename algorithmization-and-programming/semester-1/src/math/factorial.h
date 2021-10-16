//
// Created by daniil_stepanenko on 15.10.2021.
//

#ifndef UNIVERSITY_FACTORIAL_H
#define UNIVERSITY_FACTORIAL_H

#include <vector>

class FactorialCache {
public:
    FactorialCache();
    int factorial(int i);
    int factorial_sum(int n);

private:
    std::vector<int> cache;
    int calculate_factorial(int i);
};


#endif //UNIVERSITY_FACTORIAL_H
