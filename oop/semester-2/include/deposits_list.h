#ifndef UNIVERSITY_DEPOSITS_LIST_H
#define UNIVERSITY_DEPOSITS_LIST_H

#include "./abstract_deposit.h"


class DepositsList : public AbstractDeposit {
public:
    DepositsList();

    double getAmount() const override;

    double CalculateCompoundPercentage(time_t from, time_t to) const override;

    void Append(AbstractDeposit *val);

    void Remove(int index);

    int Length() const;

private:
    AbstractDeposit **data; //array of pointers to instances
    int len;
    int cap;
};

#endif //UNIVERSITY_DEPOSITS_LIST_H
