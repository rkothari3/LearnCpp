/*
Write the following program: The user is asked to enter 2 floating point numbers (use doubles). The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.

Example of program:

Enter a double value: 6.2
Enter a double value: 5
Enter +, -, *, or /: *
6.2 * 5 is 31
*/
#include <iostream>

bool isEqual(char a, char b)
{
    std::cout << "Debug Print: " << a << " and " << b << " comparison\n";
    return a == b;
}

int main()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    std::cout << "Enter a double value: ";
    double y{};
    std::cin >> y;
    std::cout << "Enter +, -, *, or /: ";
    char c{};

    std::cin >> c;

    if (isEqual(c, '+'))
        std::cout << x << " " << c << " " << y << " is " << x + y << "\n";
    else if (isEqual(c, '-'))
        std::cout << x << " " << c << " " << y << " is " << x - y << "\n";
    else if (isEqual(c, '*'))
        std::cout << x << " " << c << " " << y << " is " << x * y << "\n";
    else if (isEqual(c, '/'))
        std::cout << x << " " << c << " " << y << " is " << x / y << "\n";
    else
        std::cout << "Invalid\n";
}