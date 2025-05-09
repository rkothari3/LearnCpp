#include <iostream>
#include <cstdint> // For std::int8_t, std::uint8_t

// Function that takes a double
void printDouble(double x) {
    std::cout << "printDouble: " << x << '\n';
}

// Function that takes an int
void printInt(int x) {
    std::cout << "printInt: " << x << '\n';
}

int main() {
    // --- Implicit Conversion ---
    int i = 42;
    printDouble(i); // int -> double (safe, implicit)

    // --- Implicit Conversion Warning (may warn about data loss) ---
    double d = 5.7;
    printInt(d); // double -> int (fractional part lost, may warn)

    // --- Prevent unsafe implicit conversion with brace initialization ---
    // int badInt { 5.7 }; // Uncommenting this line will cause a compile error

    // --- Explicit Conversion with static_cast ---
    printInt(static_cast<int>(d)); // double -> int (explicit, no warning)

    // --- Char/Integer Conversion ---
    char ch = 'a';
    std::cout << "Char: " << ch << " as int: " << static_cast<int>(ch) << '\n';

    // --- Signed/Unsigned Conversion (safe) ---
    unsigned int u1 = 5;
    int s1 = static_cast<int>(u1);
    std::cout << "Unsigned 5 to signed: " << s1 << '\n';

    int s2 = 5;
    unsigned int u2 = static_cast<unsigned int>(s2);
    std::cout << "Signed 5 to unsigned: " << u2 << '\n';

    // --- Signed/Unsigned Conversion (unsafe) ---
    int s3 = -1;
    std::cout << "Signed -1 to unsigned: " << static_cast<unsigned int>(s3) << '\n';

    unsigned int u3 = 4294967295;
    std::cout << "Unsigned 4294967295 to signed: " << static_cast<int>(u3) << '\n';

    // --- Special Case: std::int8_t ---
    std::int8_t myInt8 = 65; // ASCII 'A'
    std::cout << "std::int8_t printed as char: " << myInt8 << '\n'; // May print 'A'
    std::cout << "std::int8_t printed as int: " << static_cast<int>(myInt8) << '\n'; // Prints 65

    std::uint8_t myUInt8 = 66; // ASCII 'B'
    std::cout << "std::uint8_t printed as char: " << myUInt8 << '\n'; // May print 'B'
    std::cout << "std::uint8_t printed as int: " << static_cast<int>(myUInt8) << '\n'; // Prints 66

    return 0;
}
