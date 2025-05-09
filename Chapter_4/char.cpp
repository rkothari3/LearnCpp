#include <iostream>

// Uncomment one of the following defines to test a specific block
// #define TEST_OUTPUT_CHARACTERS
//#define TEST_INPUT_CHARACTERS
//#define TEST_READ_WHITESPACE

int main()
{
#ifdef TEST_OUTPUT_CHARACTERS
    // 1. Outputting Characters
    char ch1 = 'a';
    std::cout << ch1; // Output: a
    char ch2 = 98;
    std::cout << ch2; // Output: b
#endif

#ifdef TEST_INPUT_CHARACTERS
    // 2. Inputting Characters - Skips whitespace
    char ch1{};
    std::cout << "Input a character: ";
    std::cin >> ch1;
    std::cout << "You entered: " << ch1 << '\n';
#endif

#ifdef TEST_READ_WHITESPACE
    // 3. Reading Whitespace with std::cin.get()
    char ch2{};
    std::cout << "Input a character (whitespace allowed): ";
    std::cin.get(ch2);
    std::cout << "You entered: " << ch2 << '\n';
#endif

    return 0;
}