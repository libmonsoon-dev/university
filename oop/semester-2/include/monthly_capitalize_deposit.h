#ifndef UNIVERSITY_MONTHLY_CAPITALIZE_DEPOSIT_H
#define UNIVERSITY_MONTHLY_CAPITALIZE_DEPOSIT_H

#include <ctime>

#include "./base_deposit.h"

class MonthlyCapitalizeDeposit : public BaseDeposit {
public:
    MonthlyCapitalizeDeposit() : BaseDeposit() {};

    MonthlyCapitalizeDeposit(double amount, double annualPercentage, time_t created = time(nullptr)) :
            BaseDeposit(amount, annualPercentage, created) {};

    double CalculateCompoundPercentage(time_t from, time_t to) const override;
};


#endif //UNIVERSITY_MONTHLY_CAPITALIZE_DEPOSIT_H
