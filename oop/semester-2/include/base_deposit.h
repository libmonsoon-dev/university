#ifndef UNIVERSITY_BASE_DEPOSIT_H
#define UNIVERSITY_BASE_DEPOSIT_H

#include <ctime>

#include "./abstract_deposit.h"

class BaseDeposit : public AbstractDeposit {
public:
    double getAmount() const final;

    double getAnnualPercentage() const;

    time_t getCreatedTime() const;

protected:
    BaseDeposit();

    BaseDeposit(double amount, double annualPercentage, time_t created = time(nullptr));

    int DaysBetween(time_t from, time_t to) const;

private:
    double amount;
    double annualPercentage;
    time_t created;
};

#endif //UNIVERSITY_BASE_DEPOSIT_H
