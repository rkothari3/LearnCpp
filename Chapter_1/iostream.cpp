#include <iostream>
int main()
{
    int x{3};
    // std::cout << x;
    // Can have multiple insertion operators
    std::cout << x << x; // Output: 33
    // To add new line, use std::endl
    std::cout << std::endl
              << "------------" << std::endl;
    std::cout << "Line 1" << std::endl;
    std::cout << "Line 2" << std::endl;
    // Using \n however is preferred over endl because it simply inserts a newline rather than flushing the output buffer.
    std::cout << '\n'
              << "HelloWorld" << '\n';
    std::cout << "More Conventional Between Double quotes\n";

    // std::cin
    /*
     * - Another predefined variable in iostream.
     * - reads input from keyboard
     * - we use the extraction operator (>>)
     */
    std::cout << "Enter a number: ";
    int y{}; // If we enter a string, then it will ouput 0.
    std::cin >> y;
    std::cout << "You entered " << y << '\n';

    // Quiz: Coding Challenge - Enter 3 nums
    std::cout << "Enter 3 numbers: ";
    // Intialize variables
    int a{}, b{}, c{};
    std::cin >> a >> b >> c;
    std::cout << "Here are ur numbers" << a << b << c;

    return 0;
}