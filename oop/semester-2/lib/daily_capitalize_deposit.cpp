#include <cmath>

#include "../include/daily_capitalize_deposit.h"
#include "../include/time_utils.h"

double DailyCapitalizeDeposit::CalculateCompoundPercentage(time_t from, time_t to) const {
    auto days = this->DaysBetween(from, to);
    if (days == 0) {
        return 0;
    }

    auto rate = 1 + (this->getAnnualPercentage() / 100 / DAYS_IN_YEAR);

    return this->getAmount() * pow(rate, days) - this->getAmount();
}


