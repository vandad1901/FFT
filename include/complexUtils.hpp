#ifndef COMPLEXUTILS_HPP
#define COMPLEXUTILS_HPP
#include <cmath>
#include "complex.hpp"

Complex cis(double theta);
unsigned long upper_power_of_two(unsigned long v);
template <typename T>
T power(T x, long long int y)
{
    T r = 1;
    while (y > 0)
    {
        if (y & 1)
            r = (r * x);
        x = (x * x);
        y = y / 2;
    }
    return r;
}
#endif