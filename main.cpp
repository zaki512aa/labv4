/*
 * кто выполнил: Александр Синяков
 * что делает программа1: ооп перегрузка операторов
 * на входе: ввод чисел с клавиатуры
 * на выходе: результат вычислений на экран
 */

#include <iostream>
#include <limits>
#include "Complex.h"
#include "Rational.h"

using namespace std;

// очистка буфера при плохом вводе
void clear_input() {
    cin.clear();
    cin.ignore(10000, 10);
    cout << "oshibka vvoda. poprobuyte eshe raz: ";
}

void test_complex() {
    cout << "=== test classa complex ===" << endl;
    Complex c1, c2;

    // ввод
    cout << "vvedite dva chisla dlya c1 (cherez probel): ";
    while (!(cin >> c1)) clear_input();

    cout << "vvedite dva chisla dlya c2 (cherez probel): ";
    while (!(cin >> c2)) clear_input();

    // печать введенных данных
    cout << "kontrolniy vyvod:" << endl;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex c3 = c1; // тест копирования
    cout << "kopiya c1 (teper eto c3) = " << c3 << endl;

    cout << "arifmetika:" << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;

    try {
        cout << "c1 / c2 = " << c1 / c2 << endl;
    } catch(const exception& e) {
        cout << "c1 / c2 = oshibka: " << e.what() << endl;
    }

    cout << "inkrement i dekrement:" << endl;
    cout << "++c1 = " << ++c1 << endl;
    cout << "c1++ = " << c1++ << " (posle etogo c1 = " << c1 << ")" << endl;
    cout << "--c1 = " << --c1 << endl;

    cout << "logika po modulyu:" << endl;
    cout << "c1 > c2: " << (c1 > c2 ? "da" : "net") << endl;
    cout << "c1 == c2: " << (c1 == c2 ? "da" : "net") << endl;
}

void test_rational() {
    cout << "\n=== test classa rational ===" << endl;
    Rational r1, r2;

    cout << "vvedite chislitel i znamenatel r1 (cherez probel): ";
    while (!(cin >> r1)) clear_input();

    cout << "vvedite chislitel i znamenatel r2 (cherez probel): ";
    while (!(cin >> r2)) clear_input();

    cout << "kontrolniy vyvod:" << endl;
    cout << "r1 = " << r1 << " (chislitel: " << r1.Numerator() << ", znamenatel: " << r1.Denominator() << ")" << endl;
    cout << "r2 = " << r2 << endl;

    cout << "arifmetika:" << endl;
    cout << "r1 + r2 = " << r1 + r2 << endl;
    cout << "r1 - r2 = " << r1 - r2 << endl;
    cout << "r1 * r2 = " << r1 * r2 << endl;

    try {
        cout << "r1 / r2 = " << r1 / r2 << endl;
    } catch(const exception& e) {
        cout << "r1 / r2 = oshibka: " << e.what() << endl;
    }

    cout << "operacii s celimi chislami:" << endl;
    cout << "r1 + 5 = " << r1 + 5 << endl;
    cout << "5 * r1 = " << 5 * r1 << endl;

    cout << "unarniy minus:" << endl;
    cout << "-r1 = " << -r1 << endl;

    Rational r3 = r1;
    r3 += r2;
    cout << "r3 (eto r1) += r2. teper r3 = " << r3 << endl;

    cout << "logika:" << endl;
    cout << "r1 == r2: " << (r1 == r2 ? "da" : "net") << endl;
    cout << "r1 != r2: " << (r1 != r2 ? "da" : "net") << endl;
}

int main() {
    test_complex();
    test_rational();
    return 0;
}