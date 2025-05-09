#include <iostream>

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x {};
	readNumber(x);
	x = x + readNumber(x);
	writeAnswer(x);

	return 0;
}

/*
The major issue here is in the second line of function main -- the return value of readNumber isn’t assigned to anything, so it is discarded. A minor issue is that readNumber is taking an argument when it should have a local variable instead.
*/