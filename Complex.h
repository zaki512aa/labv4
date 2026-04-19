#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double re;
    double im;

public:
    // конструкторы
    Complex();
    Complex(double x, double y);
    Complex(const Complex& other); // копирование

    // присваивание
    Complex& operator=(const Complex& other);

    // арифметика
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend Complex operator-(const Complex& lhs, const Complex& rhs);
    friend Complex operator*(const Complex& lhs, const Complex& rhs);
    friend Complex operator/(const Complex& lhs, const Complex& rhs);

    // инкремент и декремент (+1 и -1 к полям)
    Complex& operator++();    // префикс
    Complex operator++(int);  // постфикс
    Complex& operator--();    // префикс
    Complex operator--(int);  // постфикс

    // модуль для сравнения
    double get_module() const;

    // логика (по модулю)
    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // ввод и вывод
    friend std::ostream& operator<<(std::ostream& os, const Complex& obj);
    friend std::istream& operator>>(std::istream& is, Complex& obj);
};

#endif