#include <cmath>
#include <algorithm>

#include "../include/decimal.h"

#define DIVISION_PRECISION 16

Decimal::Decimal() {
    this->value = 0;
    this->exp = 0;
};

Decimal::Decimal(int value, int exp) {
    this->value = value;
    this->exp = exp;
};

Decimal::Decimal(double value, int roundToDigits) {
    if (roundToDigits < 0) {
        throw "invalid roundToDigits value";
    }
    value *= pow(10, roundToDigits);
    this->value = value;
    this->exp = -roundToDigits;
}

Decimal *Decimal::RescalePair(Decimal other) const {
    static Decimal result[2];

    if (this->exp == other.exp) {
        result[0] = *this;
        result[1] = other;
        return result;
    }

    auto baseScale = std::min(this->exp, other.exp);
    if (baseScale != this->exp) {
        result[0] = this->Rescale(baseScale);
        result[1] = other;
    } else {
        result[0] = *this;
        result[1] = other.Rescale(baseScale);
    }

    return result;
};

Decimal Decimal::Rescale(int exp) const {
    if (this->exp == exp) {
        return {this->value, this->exp};
    }

    auto diff = abs(exp - this->exp);
    auto v = this->value;

    auto expScale = pow(10, diff);
    if (exp > this->exp) {
        v /= expScale;
    } else if (exp < this->exp) {
        v *= expScale;
    }

    return {v, exp};
};

bool Decimal::operator==(const Decimal other) const {
    auto pair = this->RescalePair(other);

    return pair[0].value == pair[1].value;
}


Decimal Decimal::operator+(const Decimal other) const {
    auto pair = this->RescalePair(other);

    return {pair[0].value + pair[1].value, pair[0].exp};
}

Decimal Decimal::operator-(const Decimal other) const {
    auto pair = this->RescalePair(other);

    return {pair[0].value - pair[1].value, pair[0].exp};
}

Decimal &Decimal::operator+=(const Decimal &other) {
    *this = *this + other;

    return *this;
}


std::string Decimal::ToString() const {
    if (this->exp >= 0) {
        return std::to_string(this->Rescale(0).value);
    };

    std::string str = std::to_string(abs(this->value));

    std::string intPart;
    std::string fractionalPart;

    if (str.length() > -this->exp) {
        intPart = str.substr(0, str.length() + this->exp);
        fractionalPart = str.substr(str.length() + this->exp);
    } else {
        intPart = "0";

        auto num0s = -this->exp - str.length();
        fractionalPart = std::string(num0s, '0') + str;
    }

    auto i = fractionalPart.length() - 1;
    for (; i >= 0; i--) {
        if (fractionalPart[i] != '0') {
            break;
        }
    }
    fractionalPart = fractionalPart.substr(0, i + 1);


    std::string number = intPart;
    if (fractionalPart.length() > 0) {
        number += "." + fractionalPart;
    }

    if (this->value < 0) {
        return "-" + number;
    }

    return number;
}

Decimal Decimal::operator/(const Decimal other) {
    return Decimal();

    this->QuoRem(other);
}

Decimal Decimal::operator/(int other) {
    return *this / Decimal(other);
}

Decimal *Decimal::QuoRem(const Decimal other) {
    static Decimal pair[2];

    if (other.value == 0) {
        "decimal division by 0";
    }

    auto scale = -DIVISION_PRECISION;
    auto e = this->exp - other.exp - scale;

    int aa, bb, expo, scalerest;

    if (e < 0) {
        aa = this->value;
        expo = -e;
        bb = pow(10, expo);
        bb = other.value * bb;
        scalerest = this->exp;
    } else {
        expo = e;
        aa = pow(10, expo);
        aa = (this->value, aa);
        bb = other.value;
        scalerest = scale + other.exp;
    }

//    TODO: implement this
//    var q, r big.Int
//    q.QuoRem(&aa, &bb, &r)
//    dq := Decimal{value: &q, exp: scale}
//    dr := Decimal{value: &r, exp: scalerest}
//    pair[0] = {q, scale};
//    pair[1] = {r, scalerest};

    return pair;
}

std::ostream &operator<<(std::ostream &out, Decimal d) {
    out << d.ToString();
    return out;
}
