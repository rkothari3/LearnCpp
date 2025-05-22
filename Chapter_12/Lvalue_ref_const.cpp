#include <iostream>

int main()
{
    int x {4};
    const int& ref {x};

    std::cout << x << '\n';
    std::cout << ref << '\n';

    // ref = 6; // Error
    x = 5;

    std::cout << x << '\n';
    std::cout << ref << '\n';
}