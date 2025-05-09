# Chapter 4: Fundamental Data Types #
- Void functions do not return a value.
- Deprecated: functions that do not take parameters.
- Void keyword also used in regards as a void pointer, but more on that later.
- An object must occupy atleast 1 byte. 
- The integral types char, short, int, long, and long long have a minimum size of 8, 16, 16, 32, and 64 bits respectively. Char has exactly 1 byte (8 bits).
- Memory is byte-addressed in C++, meaning we can access every byte of memory independently.

- The sizeof operator is a unary operator that takes either a type or a variable, and returns the size of an object of that type (in bytes).
```cpp
#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    return 0;
}
```

- Signed integers: number's sign is stored as part of the value.
- An n-bit signed variable has a range of -(2^(n-1)) to (2^(n-1))-1.
- To define signed integers, the best practice is no the use the int suffix or signed prefix.
Example:
```cpp
short s;      // prefer "short" instead of "short int"
int i;
long l;       // prefer "long" instead of "long int"
long long ll; // prefer "long long" instead of "long long int"

// Can also use the signed keyword, along with 's' if wanted.
signed short ss;
signed int si;
signed long sl;
signed long long sll;
```

- Unsigned Integers
- To define unsigned integers, we use the unsigned keyword.
- An n-bit unsigned variable has a range of 0 to (2^n)-1.
```cpp
unsigned short us;
unsigned int ui;
unsigned long ul;
unsigned long long ull;
```

### Fixed-Size Integer Types
- These fixed-width integers are defined in the `<cstdint>` header
- NOTE: `std::int8_t` and `std::uint8_t` may behave like characters rather than integers on some systems, as 8-bit fixed-width integer types are often treated as character types. This behavior doesn't affect 16-bit or wider integral types.
| Name           | Fixed Size      | Fixed Range                              |
|----------------|-----------------|------------------------------------------|
| `std::int8_t`  | 1 byte signed   | -128 to 127                              |
| `std::uint8_t` | 1 byte unsigned | 0 to 255                                 |
| `std::int16_t` | 2 byte signed   | -32,768 to 32,767                        |
| `std::uint16_t`| 2 byte unsigned | 0 to 65,535                              |
| `std::int32_t` | 4 byte signed   | -2,147,483,648 to 2,147,483,647          |
| `std::uint32_t`| 4 byte unsigned | 0 to 4,294,967,295                       |
| `std::int64_t` | 8 byte signed   | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| `std::uint64_t`| 8 byte unsigned | 0 to 18,446,744,073,709,551,615          |

### Best practice

- **Prefer `int`** when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether `int` is 16-bits or 32-bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
- **Prefer `std::int#_t`** when storing a quantity that needs a guaranteed range.
- **Prefer `std::uint#_t`** when doing bit manipulation or well-defined wrap-around behavior is required (e.g. for cryptography or random number generation).

### Avoid the following when possible:
- `short` and `long` integers (prefer a fixed-width integer type instead).
- The fast and least integral types (prefer a fixed-width integer type instead).
- Unsigned types for holding quantities (prefer a signed integer type instead).
- The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
- Any compiler-specific fixed-width integers (for example, Visual Studio defines `__int8`, `__int16`, etc…).

## Floating Point Types in C++: Concise Notes

**What are Floating Point Types?**
- Used to store numbers with fractional components (e.g., 4320.0, -3.33, 0.01226).
- The decimal point can "float" (variable number of digits before/after decimal).
- Always signed (can be positive or negative).

**C++ Floating Point Types**

| Type         | Typical Size | Precision (Digits) | Range (Approximate)         |
|--------------|--------------|---------------------|-----------------------------|
| float        | 4 bytes      | 6–9 (typically 7)  | ±1.18×10⁻³⁸ to ±3.4×10³⁸    |
| double       | 8 bytes      | 15–18 (typically 16)| ±2.23×10⁻³⁰⁸ to ±1.8×10³⁰⁸  |
| long double  | 8,12,16 bytes| 15–36              | Platform-dependent          |

- `float`: Usually IEEE 754 single-precision (4 bytes).
- `double`: Usually IEEE 754 double-precision (8 bytes).
- `long double`: Varies by platform; avoid unless necessary.

**Declaring and Initializing**

```cpp
float f;
double d;
long double ld;

int a { 5 };        // converts to double
double b { 5.0 };   // defaults to double
float c { 5.0f };   // 'f' suffix for float
```

- Always include a decimal point for floating point literals (e.g., 5.0).
- By default, floating point literals are `double` unless suffixed with 'f' (`float`).

**Best Practice**
- Match the literal type to the variable type to avoid unnecessary conversion and possible precision loss.

**Printing Floating Point Numbers**

```cpp
#include <iostream>
int main() {
    float f {123456789.0f};
    std::cout << f << '\n'; // may lose precision
    return 0;
}
```

**Best Practices**
- Prefer `double` over `float` for better precision unless memory is a concern.
- Avoid using floating point for financial/currency data due to rounding errors.
- Avoid division by zero, even if your compiler supports special values.

**Key Takeaways**
- Floating point types are essential for representing real numbers but have inherent precision limitations and rounding errors.
- Always be cautious with equality comparisons and repeated arithmetic operations on floating point numbers.

### Boolean
- When we print boolean values, std::cout prints 0 for false and 1 for true:
```cpp
// Look at codes to get a better understanding!
```

## If statements
"If condition is true, then statement runs, else false statement"
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    if (x == 0)
        std::cout << "The value is 0\n";
    else
        std::cout << "The value is not 0\n";
}
```
- Note: non-zero integer is true, and zero is false.
```cpp
int x {4};
if (x)
    std::cout << "hi\n"; // prints "hi" because 4 is non-zero
else
    std::cout << "bye\n";
```

### Chapter Review

The smallest unit of memory is a binary digit, also called a bit. The smallest unit amount of memory that can be addressed (accessed) directly is a byte. The modern standard is that a byte equals 8 bits.

A data type tells the compiler how to interpret the contents of memory in some meaningful way.

C++ comes with support for many fundamental data types, including floating point numbers, integers, boolean, chars, null pointers, and void.

Void is used to indicate no type. It is primarily used to indicate that a function does not return a value.

Different types take different amounts of memory, and the amount of memory used may vary by machine.

#### Related content

See 4.3 -- Object sizes and the sizeof operator for a table indicating the minimum size for each fundamental type.

The sizeof operator can be used to return the size of a type in bytes.

Signed integers are used for holding positive and negative whole numbers, including 0. The set of values that a specific data type can hold is called its range. When using integers, keep an eye out for overflow and integer division problems.

Unsigned integers only hold positive numbers (and 0), and should generally be avoided unless you’re doing bit-level manipulation.

Fixed-width integers are integers with guaranteed sizes, but they may not exist on all architectures. The fast and least integers are the fastest and smallest integers that are at least some size. `std::int8_t` and `std::uint8_t` should generally be avoided, as they tend to behave like chars instead of integers.

`size_t` is an unsigned integral type that is used to represent the size or length of objects.

Scientific notation is a shorthand way of writing lengthy numbers. C++ supports scientific notation in conjunction with floating point numbers. The digits in the significand (the part before the `e`) are called the significant digits.

Floating point is a set of types designed to hold real numbers (including those with a fractional component). The precision of a number defines how many significant digits it can represent without information loss. A rounding error can occur when too many significant digits are stored in a floating point number that can’t hold that much precision. Rounding errors happen all the time, even with simple numbers such as 0.1. Because of this, you shouldn’t compare floating point numbers directly.

The Boolean type is used to store a true or false value.

If statements allow us to execute one or more lines of code if some condition is true. The conditional expression of an if-statement is interpreted as a boolean value. An else statement can be used to execute a statement when a prior if-statement condition evaluates to false.

Char is used to store values that are interpreted as an ASCII character. When using chars, be careful not to mix up ASCII code values and numbers. Printing a char as an integer value requires use of `static_cast`.

Angled brackets are typically used in C++ to represent something that needs a parameterizable type. This is used with `static_cast` to determine what data type the argument should be converted to (e.g. `static_cast<int>(x)` will return the value of `x` as an int).
