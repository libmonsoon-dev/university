#ifndef UNIVERSITY_DECIMAL_H
#define UNIVERSITY_DECIMAL_H

#include <ostream>


class Decimal {
public:
    Decimal();

    Decimal(int value, int exp = 0);

    Decimal(double value, int roundToDigits = 2);

    bool operator==(const Decimal other) const;

    Decimal operator+(const Decimal other) const;

    Decimal operator-(const Decimal other) const;

    Decimal &operator+=(const Decimal &other);

    Decimal operator/(const Decimal other);

    Decimal operator/(int other);

    std::string ToString() const;

    Decimal Rescale(int exp) const;

    Decimal *RescalePair(Decimal other) const;

private:
    int value;

    int exp;

    Decimal *QuoRem(const Decimal decimal);
};

std::ostream &operator<<(std::ostream &out, Decimal d);

#endif //UNIVERSITY_DECIMAL_H
