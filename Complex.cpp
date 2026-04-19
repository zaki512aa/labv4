#include "Complex.h"
#include <cmath>
#include <stdexcept>

Complex::Complex() : re(0.0), im(0.0) {}

Complex::Complex(double x, double y) : re(x), im(y) {}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.im * rhs.re + lhs.re * rhs.im);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
    if (denominator == 0) {
        throw std::invalid_argument("delenie na nol v complex");
    }
    return Complex((lhs.re * rhs.re + lhs.im * rhs.im) / denominator,
                   (lhs.im * rhs.re - lhs.re * rhs.im) / denominator);
}

Complex& Complex::operator++() {
    re += 1;
    im += 1;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    ++(*this);
    return temp;
}

Complex& Complex::operator--() {
    re -= 1;
    im -= 1;
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp = *this;
    --(*this);
    return temp;
}

double Complex::get_module() const {
    return std::sqrt(re * re + im * im);
}

bool Complex::operator>(const Complex& other) const {
    return this->get_module() > other.get_module();
}

bool Complex::operator<(const Complex& other) const {
    return this->get_module() < other.get_module();
}

bool Complex::operator==(const Complex& other) const {
    return this->get_module() == other.get_module();
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Complex& obj) {
    os << obj.re;
    if (obj.im >= 0) os << " + " << obj.im << "* i";
    else os << " - " << -obj.im << "* i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& obj) {
    is >> obj.re >> obj.im;
    return is;
}