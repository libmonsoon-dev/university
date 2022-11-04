#include <algorithm>
#include "../include/base_deposit.h"
#include "../include/time_utils.h"


BaseDeposit::BaseDeposit() {
    this->amount = 0;
    this->annualPercentage = 0;
    this->created = time(nullptr);
}

BaseDeposit::BaseDeposit(double amount, double annualPercentage, time_t created) {
    this->amount = amount;
    this->annualPercentage = annualPercentage;
    this->created = created;
}

double BaseDeposit::getAmount() const {
    return this->amount;
}

double BaseDeposit::getAnnualPercentage() const {
    return this->annualPercentage;
}

inline time_t BaseDeposit::getCreatedTime() const {
    return this->created;
}

int BaseDeposit::DaysBetween(time_t from, time_t to) const {
    from = std::max(from, this->getCreatedTime());
    if (from > to) {
        return 0;
    }

    return difftime(to, from) / SECONDS_IN_DAY;
}
