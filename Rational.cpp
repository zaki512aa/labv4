#include "Rational.h"
#include <numeric>
#include <stdexcept>

void Rational::normalize() {
    if (den == 0) {
        throw std::invalid_argument("znamenatel raven nulu");
    }
    int gcd_val = std::gcd(num, den);
    num /= gcd_val;
    den /= gcd_val;
    
    // знаменатель всегда с плюсом
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

Rational::Rational(int numerator, int denominator) : num(numerator), den(denominator) {
    normalize();
}

int Rational::Numerator() const { return num; }
int Rational::Denominator() const { return den; }

Rational Rational::operator+() const { return *this; }
Rational Rational::operator-() const { return Rational(-num, den); }

Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num * rhs.den + rhs.num * lhs.den, lhs.den * rhs.den);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num * rhs.den - rhs.num * lhs.den, lhs.den * rhs.den);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.num == 0) throw std::invalid_argument("delenie na nol");
    return Rational(lhs.num * rhs.den, lhs.den * rhs.num);
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

bool Rational::operator==(const Rational& other) const {
    return (num == other.num) && (den == other.den);
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Rational& obj) {
    os << obj.num << "/" << obj.den;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& obj) {
    is >> obj.num >> obj.den;
    obj.normalize();
    return is;
}