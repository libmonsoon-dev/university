#include <cmath>

#include "../include/monthly_capitalize_deposit.h"
#include "../include/time_utils.h"

double MonthlyCapitalizeDeposit::CalculateCompoundPercentage(time_t from, time_t to) const {
    auto days = this->DaysBetween(from, to);
    if (days == 0) {
        return 0;
    }

    auto rate = 1 + (this->getAnnualPercentage() / 100 / MOUNTS_IN_YEAR);
    return this->getAmount() * pow(rate, static_cast<double>(days / DAYS_IN_MOUNT)) - this->getAmount();
}
