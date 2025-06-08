// Sizing of the struct is atleast the sum of its members, but often more than that.
// The member orders also affect size.

// TIP: Define members in decreasing order of size to minimize padding.
#include <iostream>

struct Foo1
{
    short a{};
    int b{};
    short c{};
};

struct Foo2
{
    int b{};
    short a{};
    short c{};
};

int main()
{
    std::cout << "Foo1: " << sizeof(short) << '\n'; // prints 12
    std::cout << "Foo2: " << sizeof(int) << '\n'; // prints 8
    std::cout << "Foo1: " << sizeof(Foo1) << '\n'; // prints 12
    std::cout << "Foo2: " << sizeof(Foo2) << '\n'; // prints 8
    return 0;
}
