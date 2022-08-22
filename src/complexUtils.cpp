#include "complex.hpp"
#include "complexUtils.hpp"

Complex cis(double theta)
{
    return {std::cos(theta), std::sin(theta)};
}

unsigned long upper_power_of_two(unsigned long v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}