#ifndef FFT_H
#define FFT_H
#include <vector>
#include "complex.hpp"

std::vector<Complex> FFT(std::vector<Complex> p);
std::vector<Complex> IFFT(std::vector<Complex> p);
std::vector<Complex> IFFT_INTERNAL(std::vector<Complex> p);
#endif