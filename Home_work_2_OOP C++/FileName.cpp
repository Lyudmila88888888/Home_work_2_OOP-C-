#include "Fraction.hpp"
#include <iostream>
#include <cmath>

// Приватный метод для вычисления НОД
unsigned int Fraction::gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Приватный метод сокращения дроби
void Fraction::reduce() {
    unsigned int gcd_value = this->gcd(this->numerator, this->denominator);
    this->numerator /= gcd_value;
    this->denominator /= gcd_value;
}

// Параметрический конструктор
Fraction::Fraction(unsigned int numerator, unsigned int denominator, bool is_positive)
    : numerator(numerator), denominator(denominator), is_positive(is_positive) {
    reduce();
}

// Конструктор по умолчанию
Fraction::Fraction() : Fraction(1, 1, true) {}

// Конструктор копирования
Fraction::Fraction(const Fraction& other)
    : Fraction(other.numerator, other.denominator, other.is_positive) {}

// Метод вывода дроби в консоль
void Fraction::print() const {
    std::cout << (is_positive ? "" : "-") << numerator << "/" << denominator << std::endl;
}

// Методы сложения/вычитания дроби с другой дробью
Fraction Fraction::add(const Fraction& other) const {
    unsigned int common_denominator = this->denominator * other.denominator;
    int this_numerator = this->numerator * other.denominator;
    int other_numerator = other.numerator * this->denominator;
    int result_numerator = (this->is_positive ? this_numerator : -this_numerator) +
        (other.is_positive ? other_numerator : -other_numerator);
    bool result_is_positive = result_numerator >= 0;

    return Fraction(std::abs(result_numerator), common_denominator, result_is_positive);
}

Fraction Fraction::subtract(const Fraction& other) const {
    unsigned int common_denominator = this->denominator * other.denominator;
    int this_numerator = this->numerator * other.denominator;
    int other_numerator = other.numerator * this->denominator;
    int result_numerator = (this->is_positive ? this_numerator : -this_numerator) -
        (other.is_positive ? other_numerator : -other_numerator);
    bool result_is_positive = result_numerator >= 0;

    return Fraction(std::abs(result_numerator), common_denominator, result_is_positive);
}

// Методы сложения/вычитания дроби с целым числом
Fraction Fraction::add(int value) const {
    int result_numerator = (this->is_positive ? this->numerator : this->numerator) + value * this->denominator;
    bool result_is_positive = result_numerator >= 0;

    return Fraction(std::abs(result_numerator), this->denominator, result_is_positive);
}

Fraction Fraction::subtract(int value) const {
    int result_numerator = (this->is_positive ? this->numerator : this->numerator) - value * this->denominator;
    bool result_is_positive = result_numerator >= 0;

    return Fraction(std::abs(result_numerator), this->denominator, result_is_positive);
}
int main() {
    Fraction frac1(3, 4, true);
    Fraction frac2(5, 8, false);

    frac1.print();
    frac2.print();

    Fraction result1 = frac1.add(frac2);
    result1.print();

    Fraction result2 = frac1.subtract(frac2);
    result2.print();

    Fraction result3 = frac1.add(2);
    result3.print();

    Fraction result4 = frac1.subtract(2);
    result4.print();

    return 0;
}