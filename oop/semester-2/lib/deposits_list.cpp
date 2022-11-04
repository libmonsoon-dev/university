#include "../include/deposits_list.h"

#define MIN_DEPOSITS_LIST_CAP 10

DepositsList::DepositsList() {
    this->len = 0;
    this->cap = MIN_DEPOSITS_LIST_CAP;
    this->data = new AbstractDeposit *[this->cap];
}

double DepositsList::getAmount() const {
    double result = 0;

    for (int i = 0; i < this->len; i++) {
        result += this->data[i]->getAmount();
    }

    return result;
}

double DepositsList::CalculateCompoundPercentage(time_t from, time_t to) const {
    double result = 0;

    for (int i = 0; i < this->len; i++) {
        result += this->data[i]->CalculateCompoundPercentage(from, to);
    }

    return result;

}

void DepositsList::Append(AbstractDeposit *val) {
    if (this->len == this->cap) {
        this->cap *= 2;
        auto oldData = this->data;
        this->data = new AbstractDeposit *[this->cap];

        for (int i = 0; i < this->len; i++) {
            this->data[i] = oldData[i];
        }

        delete[] oldData;
    }

    this->data[this->len] = val;
    this->len++;
}

void DepositsList::Remove(int index) {
    for (int i = index; i < this->len - 1; i++) {
        this->data[i] = this->data[i + 1];
    }

    this->len--;
}

int DepositsList::Length() const {
    return this->len;
}
