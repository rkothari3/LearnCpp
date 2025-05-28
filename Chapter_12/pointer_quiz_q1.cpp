#include <iostream>

int main()
{
	short value{ 7 }; // &value = 0012FF60
	short otherValue{ 3 }; // &otherValue = 0012FF54

	short* ptr{ &value };

	std::cout << &value << '\n'; // 0012FF60
	std::cout << value << '\n'; // 7
	std::cout << ptr << '\n'; // 0012FF60
	std::cout << *ptr << '\n'; // 7
	std::cout << '\n';

	*ptr = 9;

	std::cout << &value << '\n'; // 0012FF60
	std::cout << value << '\n'; // 9
	std::cout << ptr << '\n'; // 0012FF60
	std::cout << *ptr << '\n'; // 9
	std::cout << '\n';

	ptr = &otherValue;

	std::cout << &otherValue << '\n'; // 0012FF54
	std::cout << otherValue << '\n'; // 3
	std::cout << ptr << '\n'; // 0012FF54
	std::cout << *ptr << '\n'; // 3
	std::cout << '\n';

	std::cout << sizeof(ptr) << '\n'; // 8
	std::cout << sizeof(*ptr) << '\n'; // 2

	return 0;
}