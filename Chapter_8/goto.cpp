#include <iostream>
#include <cmath> // for sqrt()

int main()
{
    double x{};
tryagain:
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0)
    {
        goto tryagain;
    }

    std::cout << std::sqrt(x);
    return 0;
}