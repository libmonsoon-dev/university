#ifndef UNIVERSITY_QUARTERLY_CAPITALIZE_DEPOSIT_H
#define UNIVERSITY_QUARTERLY_CAPITALIZE_DEPOSIT_H

#include <ctime>

#include "./base_deposit.h"

class QuarterlyCapitalizeDeposit : public BaseDeposit {
public:
    QuarterlyCapitalizeDeposit() : BaseDeposit() {};

    QuarterlyCapitalizeDeposit(double amount, double annualPercentage, time_t created = time(nullptr)) :
            BaseDeposit(amount, annualPercentage, created) {};

    double CalculateCompoundPercentage(time_t from, time_t to) const override;
};

#endif //UNIVERSITY_QUARTERLY_CAPITALIZE_DEPOSIT_H
