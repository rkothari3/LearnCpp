#include <iostream>

int main()
{
    std::cout << true << '\n';
    std::cout << false << '\n';

    // boolalpha doesn't output anything, but manipulates the way std::cout ouputs bool
    std::cout << std::boolalpha; // print bools as true or false

    std::cout << true << '\n';
    std::cout << false << '\n';
    return 0;
}