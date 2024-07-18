#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

class Fraction {
private:
    unsigned int numerator;
    unsigned int denominator;
    bool is_positive;

    void reduce(); // Приватный метод сокращения дроби
    unsigned int gcd(unsigned int a, unsigned int b); // Приватный метод для вычисления НОД

public:
    // Параметрический конструктор
    Fraction(unsigned int numerator, unsigned int denominator, bool is_positive = true);

    // Конструктор по умолчанию
    Fraction();

    // Конструктор копирования
    Fraction(const Fraction& other);

    // Метод вывода дроби в консоль
    void print() const;

    // Методы сложения/вычитания дроби с другой дробью
    Fraction add(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;

    // Методы сложения/вычитания дроби с целым числом
    Fraction add(int value) const;
    Fraction subtract(int value) const;
};

#endif // FRACTION_HPP