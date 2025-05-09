#include <iostream>

int main()
{
	bool bFalse { 0 }; // okay: initialized to false
	bool bTrue  { 1 }; // okay: initialized to true
	bool bNo    { 2 }; // error: narrowing conversions disallowed

	std::cout << bFalse << bTrue << bNo << '\n';

    // However, in any context where an integer can be converted to a Boolean, the integer 0 is converted to false, and any other integer is converted to true.
    std::cout << std::boolalpha; // print bools as true or false

	bool b1 = 4 ; // copy initialization allows implicit conversion from int to bool
	std::cout << b1 << '\n';

	bool b2 = 0 ; // copy initialization allows implicit conversion from int to bool
	std::cout << b2 << '\n';

    bool b{}; // default initialize to false
	std::cout << "Enter a boolean value: ";
	std::cin >> b;
	std::cout << "You entered: " << b << '\n';
    // This will ouput 0 because cin only accepts numeric input for boolean variables.
    // Any non-numeric value is False, and any numeric value besides 0 is true.
	return 0;
}