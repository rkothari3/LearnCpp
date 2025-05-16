// A prime number is a natural number greater than 1 that is evenly divisible (with no remainder) only by 1 and itself.

// Complete the following program by writing the isPrime() function using a for-loop. When successful, the program will print “Success!”.

// Make sure that assert triggers even if we compile in release mode
#undef NDEBUG

#include <cassert> // for assert
#include <iostream>

bool isPrime(int x)
{
    // For x is negative, 0, or 1 -> number not prime
    if (x<=1)
        return false;

    for (int num{2}; num < x; ++num)
    {
        if (x % num == 0)
            return false;
        // If num is divisible by any number other than 1 or itself than it not prime.
    }
    return true;
    
}

int main()
{
    std::cout << std::boolalpha << isPrime(2) << '\n';
    std::cout << std::boolalpha << isPrime(3) << '\n';
    std::cout << std::boolalpha << isPrime(4) << '\n';
    std::cout << std::boolalpha << isPrime(5) << '\n';
    std::cout << std::boolalpha << isPrime(6) << '\n';
    std::cout << "Ending Program...\n";

    return 0;
}