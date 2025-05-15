#include <iostream>

int main()
{
    constexpr double gravity{9.8};

    if constexpr (gravity == 9.8) // now using constexpr if
        std::cout << "Gravity is normal.\n";
    else
        std::cout << "We are not on Earth.\n";

    return 0;
}

/*
When the above code is compiled, the compiler will evaluate the conditional at compile time, see that it is always true, and keep only the single statement std::cout << "Gravity is normal.\n";.

In other words, it will compile this:

int main()
{
    constexpr double gravity{ 9.8 };

    std::cout << "Gravity is normal.\n";

    return 0;
}

*/