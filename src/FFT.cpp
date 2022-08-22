#include "FFT.hpp"
#include "complexUtils.hpp"

std::vector<Complex> FFT(std::vector<Complex> p)
{
    int n = upper_power_of_two(p.size());
    if (n == 1)
        return p;
    Complex omega = cis(2 * M_PI / n);
    std::vector<Complex> po, pe;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
            po.push_back(p[i]);

        else
            pe.push_back(p[i]);
    }
    std::vector<Complex> yo = FFT(po), ye = FFT(pe);
    std::vector<Complex> y = std::vector<Complex>(n);
    for (int i = 0; i < n / 2; i++)
    {
        y[i] = ye[i] + (omega ^ i) * yo[i];
        y[i + n / 2] = ye[i] - (omega ^ i) * yo[i];
    }
    return y;
}

std::vector<Complex> IFFT(std::vector<Complex> p)
{
    int n = upper_power_of_two(p.size());
    auto ans = IFFT_INTERNAL(p);
    for (int i = 0; i < ans.size(); ++i)
        ans[i] = ans[i] / n;
    return ans;
}
std::vector<Complex> IFFT_INTERNAL(std::vector<Complex> p)
{
    int n = upper_power_of_two(p.size());
    if (n == 1)
        return p;
    Complex omega = cis(-2 * M_PI / n);
    std::vector<Complex> po, pe;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
            po.push_back(p[i]);

        else
            pe.push_back(p[i]);
    }
    std::vector<Complex> yo = IFFT_INTERNAL(po), ye = IFFT_INTERNAL(pe);
    std::vector<Complex> y = std::vector<Complex>(n);
    for (int i = 0; i < n / 2; i++)
    {
        y[i] = ye[i] + (omega ^ i) * yo[i];
        y[i + n / 2] = ye[i] - (omega ^ i) * yo[i];
    }
    return y;
}