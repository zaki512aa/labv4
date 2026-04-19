#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    int num; // числитель
    int den; // знаменатель
    void normalize(); // сокращение

public:
    // конструктор
    Rational(int numerator = 0, int denominator = 1);

    // геттеры
    int Numerator() const;
    int Denominator() const;

    // унарные
    Rational operator+() const;
    Rational operator-() const;

    // бинарные арифметические
    friend Rational operator+(const Rational& lhs, const Rational& rhs);
    friend Rational operator-(const Rational& lhs, const Rational& rhs);
    friend Rational operator*(const Rational& lhs, const Rational& rhs);
    friend Rational operator/(const Rational& lhs, const Rational& rhs);

    // с присваиванием
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    // сравнения
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    // ввод и вывод
    friend std::ostream& operator<<(std::ostream& os, const Rational& obj);
    friend std::istream& operator>>(std::istream& is, Rational& obj);
};

#endif