// Write a function named sort2 which allows the caller to pass 2 int variables as arguments. When the function returns, the first argument should hold the lesser of the two values, and the second argument should hold the greater of the two values.

// Hint: The std::swap() function (in the <algorithm> header) can be used to swap the values of two variables. e.g. std::swap(x, y) swaps the values of the variables x and y.

// The following code should run and print the values noted in the comments:

#include <iostream>

void sort2(int& x, int& y)
{
    if (x > y)
        std::swap(x, y);
}

int main()
{
    int x { 7 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n'; // should print 7 5

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}