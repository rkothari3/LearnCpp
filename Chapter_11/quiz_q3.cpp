/*
- Output of the program
*/
#include <iostream>

template <typename T>
int count(T) // This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
{
    static int c { 0 };
    return ++c;
}

int main()
{
    std::cout << count(1) << '\n';
    std::cout << count(1) << '\n';
    std::cout << count(2.3) << '\n';
    std::cout << count<double>(1) << '\n';

    return 0;
}

/*
Output and Explaination:
1
2
1
2
When count(1) is called, the compiler will instantiate the function count<int>(int) and call it. This will return value 1.

When count(1) is called again, the compiler will see that count<int>(int) already exists, and call it again. This will return value 2.

When count(2.3) is called, the compiler will instantiate the function with prototype count<double>(double) and call it. This is a new function with its own static c variable, so this will return value 1.

When count<double>(1) is called, the compiler will see that we’re explicitly requesting the double version of count(). This function already exists due to the prior statement, so count<double>(double) will be called and the int argument will be implicitly converted to a double. This function will return value 2.
*/