# Constants and Strings

- `const` variables cannot be changed, and must be initialized.
- `const` variables can be used similarly to how object-like macros are used (e.g., `#define MYNAME`). Their added benefit is that, unlike macros, they follow the scoping rules of C++.
- A type qualifier (sometimes called a qualifier for short) is a keyword that is applied to a type that modifies how that type behaves. The `const` used to declare a constant variable is called a `const` type qualifier (or `const` qualifier for short).
- There's also a `volatile` qualifier that tells the compiler that an object may have its value changed. But this is rarely used.

### Floating-point literals

- By default, floating-point literals are of type `double`. But to make them `float`, add the suffix `f`.

```cpp
#include <iostream>

int main()
{
    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float

    return 0;
}
```

- C-style string literals are `const` objects that are created at the start of the program and are guaranteed to exist for the entirety of the program. Essentially, strings are immutable.

### As-if rule and compile-time optimization

- **Profiler**: A program used to see how long various parts of the program are taking to run.
- **Optimizer**: A program that optimizes another program.

Modern C++ compilers are optimizing compilers. They let programmers focus on writing code that is readable and maintainable without sacrificing performance.

#### Simple optimization techniques

```cpp
#include <iostream>

int main()
{
    // Constant Folding: The expression 3 + 4 can be evaluated at compile time.
    int a = 3 + 4; // Compiler folds this to int a = 7;

    // Constant Propagation: b is initialized with a constant value.
    int b = a;     // Compiler can propagate the value, so b is also 7.

    // Dead Code: c is never used, so the compiler can eliminate it.
    int c = 42;    // Dead code elimination can remove this line.

    // Using const helps the compiler optimize further.
    const int d = 10; // Compiler knows d can never change.

    // Combined: e is initialized using const variables, which can be optimized.
    const int e = b + d; // Compiler can propagate b (7) and d (10), fold to e = 17

    // Output using all optimizations:
    std::cout << e << '\n'; // Compiler can optimize this to std::cout << 17 << '\n';

    return 0;
}
```

- **As-if Rule**: An optimization principle that allows compilers to change the code for better performance without changing its observable behavior.

Key Points:

- `const` + integral type + constant expression initializer = compile-time constant
- `const` + non-integral type (like `double`) = not a compile-time constant
- `constexpr` + any type + constant expression initializer = compile-time constant

- `constexpr` variables are always compile-time constants. As a result, a `constexpr` variable must be initialized with a constant expression, otherwise a compilation error will result.
- Function parameters can be `const` (although they shouldn't), but they can't be `constexpr` since their initialization value isn't determined until runtime.
- Functions can be made `constexpr` by adding it to their declaration.

```cpp
constexpr int cmax(int x, int y) // this is a constexpr function
{
    if (x > y)
        return x;
    else
        return y;
}
```

### Introduction to std::string

- **C-string literals vs. std::string**
  - **C-string**
    - Immutable.
    - Stored in ROM, can't modify directly.
  - **std::string**
    - Mutable.
    - Represents a string as a dynamic resizable object, manages memory for you, and has more features. But it is also slower.

```cpp
#include <iostream>
#include <string>

int main()
{
    // C-string literal
    std::cout << "Hello, World";

    // std::string
    std::string name {"Alex"};
    std::cout << name;
    // Can be changed, made longer or shorter.
    /*
    If std::string doesn’t have enough memory to store a string, it will request additional memory (at runtime) using a form of memory allocation known as dynamic memory allocation. This ability to acquire additional memory is part of what makes std::string so flexible, but also comparatively slow.
    */
    name = "Lebron James";
    std::cout << name;

    // Using std::string with std::cin can result in unexpected outputs.
    // This is because std::cin only reads till whitespace. So if you input "John Doe", the first std::cin reads "John", and the next std::cin reads "Doe".

    // Use std::getline() to read a full line of text.
    // - Requires two args: std::cin, string var.
    std::cout << "Enter your full name: ";
    std::string nam{};
    std::getline(std::cin >> std::ws, nam);
    std::cout << "You entered: " << nam << '\n';
    // Use std::cin >> std::ws input manipulator to ignore leading whitespace. This needs to be done for each std::getline() call, as std::ws is not preserved across calls.

    // Use .length() to get the length of the string.
    std::cout << nam.length();
}
```

### Introduction to std::string_view

- Since `std::string` is expensive to initialize (or copy), `std::string_view` provides read-only access to an existing string (of any type too).

```cpp
#include <iostream>
#include <string_view> // C++17

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" }; // now a std::string_view
    printSV(s);

    return 0;
}

/*
In this program, no copies of "Hello World" are made. 
*/
```

- **Best Practice**: Prefer `std::string_view` over `std::string` when you need a read-only string, especially for function parameters.

---

## Chapter Review

A constant is a value that may not be changed during the program’s execution. C++ supports two types of constants: **named constants** and **literals**.

- A **named constant** is a constant value that is associated with an identifier.
- A **literal constant** is a constant value not associated with an identifier.

A variable whose value cannot be changed is called a **constant variable**. The `const` keyword can be used to make a variable constant. Constant variables must be initialized. Avoid using `const` when passing by value or returning by value.

A **type qualifier** is a keyword that is applied to a type that modifies how that type behaves. As of C++23, C++ only supports `const` and `volatile` as type qualifiers.

A **constant expression** is an expression that can be evaluated at compile-time. An expression that is not a constant expression is sometimes called a runtime expression.

- A **compile-time constant** is a constant whose value is known at compile-time.
- A **runtime constant** is a constant whose initialization value isn’t known until runtime.

A `constexpr` variable must be a compile-time constant and initialized with a constant expression. Function parameters cannot be `constexpr`.

**Literals** are values inserted directly into the code. Literals have types, and literal suffixes can be used to change the type of a literal from the default type.

A **magic number** is a literal (usually a number) that either has an unclear meaning or may need to be changed later. Don’t use magic numbers in your code. Instead, use symbolic constants.

In everyday life, we count using decimal numbers, which have 10 digits. Computers use binary, which only has 2 digits. C++ also supports octal (base 8) and hexadecimal (base 16). These are all examples of **numeral systems**, which are collections of symbols (digits) used to represent numbers.

A **string** is a collection of sequential characters that is used to represent text (such as names, words, and sentences). String literals are always placed between double quotes. String literals in C++ are C-style strings, which have a strange type that is hard to work with.

- `std::string` offers an easy and safe way to deal with text strings. `std::string` lives in the `<string>` header. `std::string` is expensive to initialize (or assign to) and copy.

- `std::string_view` provides read-only access to an existing string (a C-style string literal, a `std::string`, or a `char` array) without making a copy. A `std::string_view` that is viewing a string that has been destroyed is sometimes called a **dangling view**. When a `std::string` is modified, all views into that `std::string` are invalidated, meaning those views are now invalid. Using an invalidated view (other than to revalidate it) will produce undefined behavior.

Because C-style string literals exist for the entire program, it is okay to set a `std::string_view` to a C-style string literal, and even return such a `std::string_view` from a function.

A **substring** is a contiguous sequence of characters within an existing string.

