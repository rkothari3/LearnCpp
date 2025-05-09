#include <iostream>

int add(int x, int y) // this function is supposed to perform addition
{
    // return x - y; // but it doesn't due to the wrong operator being used
    // Change to:
    return x + y;
}

int main()
{
    std::cout << "5 + 3 = " << add(5, 3) << '\n'; // should produce 8, but produces 2

    return 0;
}