#include <iostream>

int main()
{
	int x{ 4 };
	int y{ 6 };

	int& ref{ x };
	++ref; // x = 5
	ref = y; // x = y = 6
	++ref; // x = 7

	std::cout << x << ' ' << y; // x = 7, y = 6

	return 0;
}