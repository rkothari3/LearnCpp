#include <iostream>

int main()
{
    int x{5};
    std::cout << x << '\n'; // Prints the value: 5
    std::cout << &x << '\n'; // Prints the memory address
    std::cout << *(&x) << '\n'; // Prints the value at the memory address
}