#ifndef UNIVERSITY_DAILY_CAPITALIZE_DEPOSIT_H
#define UNIVERSITY_DAILY_CAPITALIZE_DEPOSIT_H

#include "./base_deposit.h"

class DailyCapitalizeDeposit : public BaseDeposit {
public:
    DailyCapitalizeDeposit() : BaseDeposit() {};

    DailyCapitalizeDeposit(double amount, double annualPercentage, time_t created = time(nullptr)) :
            BaseDeposit(amount, annualPercentage, created) {};

    double CalculateCompoundPercentage(time_t from, time_t to) const override;
};

#endif //UNIVERSITY_DAILY_CAPITALIZE_DEPOSIT_H
