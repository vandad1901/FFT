#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex
{
    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);

private:
    double r;
    double i;

public:
    Complex(double = 0, double = 0);

    double getReal() const;
    double getImaginary() const;
    void setReal(double);
    void setImaginary(double);

    friend void swap(Complex &, Complex &);
    Complex &operator=(Complex);
    Complex &operator=(double);
    Complex operator+() const;
    Complex operator-() const;
    Complex &operator+=(const Complex &);
    Complex &operator-=(const Complex &);
    Complex &operator*=(const Complex &);
    Complex &operator/=(const double &);
    Complex &operator^=(const long long int &);

    friend Complex operator+(Complex lhs, const Complex rhs);
    friend Complex operator-(Complex lhs, const Complex rhs);
    friend Complex operator*(Complex lhs, const Complex rhs);
    friend Complex operator/(Complex lhs, const double rhs);
    friend Complex operator^(Complex lhs, const long long int rhs);
};

#endif