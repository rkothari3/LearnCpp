#include <iostream>

int main()
{
    std::cout << "Enter an integer: \n";
    int x{};
    std::cin >> x;
    int double_x{x * 2};
    std::cout << "Double that number is: " << double_x << '\n';
    std::cout << "Triple that number is: " << x * 3
              << '\n';
    return 0;
}