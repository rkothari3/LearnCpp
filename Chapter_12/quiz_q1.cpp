// For each of the following expressions on the right side of operator <<, indicate whether the expression is an lvalue or rvalue:

#include <iostream>

int foo()
{
    return 5;
}

int &max(int &x, int &y)
{
    return x > y ? x : y;
}

int main()
{
    int x{5};
    int y{6};

    std::cout << 5; // Literals are rvalues.

    std::cout << x; // Lvalue

    std::cout << x + 1; // Calculates a temp. value, so expr is an rvalue

    std::cout << foo(); // return by value -> rvalue

    std::cout << max(x, y); // returns an lvalue ref. -> lvalue
}