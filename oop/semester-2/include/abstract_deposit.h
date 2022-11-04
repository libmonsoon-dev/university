#ifndef UNIVERSITY_ABSTRACT_DEPOSIT_H
#define UNIVERSITY_ABSTRACT_DEPOSIT_H

#include <ctime>

class AbstractDeposit {
public:
    virtual double getAmount() const = 0;

    virtual double CalculateCompoundPercentage(time_t from, time_t to) const = 0;
};


#endif //UNIVERSITY_ABSTRACT_DEPOSIT_H
