#include <iostream>
#include <string>

int main()
{
    // C-string literal
    std::cout << "Hello, World";

    // std::string
    std::string name {"Alex"};
    std::cout << name;
    // Can be changed, made longer or shorter.
    /*
    If std::string doesn’t have enough memory to store a string, it will request additional memory (at runtime) using a form of memory allocation known as dynamic memory allocation. This ability to acquire additional memory is part of what makes std::string so flexible, but also comparatively slow.
    */
    name = "Lebron James";
    std::cout << name;

    //using std::string with std::cin can result in unexpected ouputs.
    // This is because the std::cin only reads till whitespace. So if u input John doe, the first std::cin reads John, and then next std::cin reads doe.

    // Use std::getLine() to read full line of text.
    // - Requires two args: std::cin, string var.
    std::cout << "Enter your full name: ";
    std::string nam{};
    std::getline(std::cin >> std::ws, nam);
    std::cout << "You entered: " << nam << '\n';
    // use std::cin >> std::ws input manipulator to ignore leading whitespace. This needs to be done for each std::getline() call, as std::ws is not preserved across calls.

    // use .length() to get the length of string.
    std::cout << nam.length();
}