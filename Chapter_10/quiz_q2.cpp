/*
2a) Update the following program to use type aliases for degrees and radians values:
2b) Given the definitions for degrees and radians in the previous quiz solution, explain why the following statement will or won’t compile:
Statement: radians = degrees;
Ans: It will compile since they both type alias double
*/

#include <iostream>

using degrees = double;
using radians = double;
// Can also use typedef
// - typedef double degrees;
// - typedef double radians;

namespace constants
{
    constexpr double pi { 3.14159 };
}

radians convertToRadians(degrees degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    degrees degrees{};
    std::cin >> degrees;

    radians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}

