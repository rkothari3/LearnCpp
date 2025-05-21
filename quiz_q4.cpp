#include <iostream>

int foo(int n)
{
    return n + 10;
}

template <typename T>
int foo(T n)
{
    return n;
}

int main()
{
    std::cout << foo(1) << '\n'; // #1 -> Non-temp. Function

    short s { 2 };
    std::cout << foo(s) << '\n'; // #2 -> Temp. Function (Output: 2)

    std::cout << foo<int>(4) << '\n'; // #3 -> Explicit instantiation (Output: 4)

    std::cout << foo<int>(s) << '\n'; // #4 ->  Temp. Function (Output: 2)

    std::cout << foo<>(6) << '\n'; // #5 -> Explicit Instantiation (Output: 6)

    return 0;
}