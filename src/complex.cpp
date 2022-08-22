#include "complex.hpp"
#include "complexUtils.hpp"

Complex::Complex(double real, double imaginary)
{
    setReal(real);
    setImaginary(imaginary);
}

double Complex::getReal() const { return r; }
double Complex::getImaginary() const { return i; }
void Complex::setReal(double num) { r = num; }
void Complex::setImaginary(double num) { i = num; }

void swap(Complex &v1, Complex &v2)
{
    std::swap(v1.r, v2.r);
    std::swap(v1.i, v2.i);
}
Complex &Complex::operator=(Complex v2)
{
    swap(*this, v2);
    return *this;
}
Complex &Complex::operator=(double rhs)
{
    Complex temp = Complex(rhs);
    swap(*this, temp);
    return *this;
}
Complex Complex::operator+() const
{
    return *this;
}
Complex Complex::operator-() const
{
    Complex temp = *this;
    temp.r = -r;
    temp.i = -i;
    return temp;
}
Complex &Complex::operator+=(const Complex &rhs)
{
    Complex lhs = *this, ans = {lhs.r + rhs.r, lhs.i + rhs.i};
    swap(*this, ans);
    return *this;
}
Complex &Complex::operator-=(const Complex &rhs)
{
    Complex lhs = *this, ans = {lhs.r - rhs.r, lhs.i - rhs.i};
    swap(*this, ans);
    return *this;
}
Complex &Complex::operator*=(const Complex &rhs)
{

    Complex lhs = *this, ans = {lhs.r * rhs.r - lhs.i * rhs.i, lhs.r * rhs.i + lhs.i * rhs.r};
    swap(*this, ans);
    return *this;
}
Complex &Complex::operator/=(const double &rhs)
{

    Complex lhs = *this, ans = {lhs.r / rhs, lhs.i / rhs};
    swap(*this, ans);
    return *this;
}
Complex &Complex::operator^=(const long long int &rhs)
{
    Complex lhs = *this, ans = power<Complex>(lhs, rhs);
    swap(*this, ans);
    return *this;
}

Complex operator+(Complex lhs, const Complex rhs)
{
    lhs += rhs;
    return lhs;
}
Complex operator-(Complex lhs, const Complex rhs)
{
    lhs -= rhs;
    return lhs;
}
Complex operator*(Complex lhs, const Complex rhs)
{
    lhs *= rhs;
    return lhs;
}
Complex operator/(Complex lhs, const double rhs)
{
    lhs /= rhs;
    return lhs;
}
Complex operator^(Complex lhs, const long long int rhs)
{
    lhs ^= rhs;
    return lhs;
}

std::ostream &operator<<(std::ostream &output, const Complex &c)
{
    output << c.r << (c.i >= 0 ? "+" : "") << c.i << "i";
    return output;
}
std::istream &operator>>(std::istream &input, Complex &v)
{
    double r, i;
    input >> r;
    input.ignore();
    input >> i;
    input.ignore(2);
    v = Complex(r, i);
    return input;
}
