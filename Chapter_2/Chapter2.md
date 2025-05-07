# Chapter 2 Notes

## Functions

### Basic Format

```cpp
returnType functionName()
{
    // Body
}
```

### Key Points

- **Nested functions** are not allowed in C++
- Functions can call other functions that call other functions
- The `main()` function:
  - Must return `int`
  - Should return `0` to indicate normal execution
  - Return statement is implicitly added if not explicitly written
- **Best practice:** Make code as non-redundant as possible
- Only one `return` statement in a function will be executed
- Void functions cannot be used in expressions that require a value

### Example of Void Functions

```cpp
#include <iostream>

void printHi() 
{
    std::cout << "Hi" << '\n';
    // return 5; <-- Would be a COMPILE ERROR
}

int main() 
{
    printHi();                // Works fine
    std::cout << printHi();   // COMPILE ERROR - void function has no return value
    return 0;
}
```

### Unused Parameters

When a function parameter exists but is not used in the body:

```cpp
void doSomething(int /*count*/)
{
    // Code Body
}
```

### Variable Scope

```cpp
#include <iostream>

int add(int x, int y) // x and y enter scope here
{
    // x and y are usable only within add()
    return x + y;
} // y and x go out of scope and are destroyed here

int main()
{
    int a{ 5 }; // a is created, initialized, and enters scope here
    int b{ 6 }; // b is created, initialized, and enters scope here

    // a and b are usable only within main()
    std::cout << add(a, b) << '\n'; // calls add(5, 6)

    return 0;
} // b and a go out of scope and are destroyed here
```

> **Note:** The lifetime of a variable is checked at runtime. When a variable is destroyed, its memory is deallocated.

### Best Practices

- Define local variables as close to their first use as reasonable
- For variables needed within a function:
  - Use function parameters when the caller will provide the initialization value
  - Use local variables otherwise

### Temporary Objects in C++

A temporary object (or anonymous object) is an unnamed object created by the compiler to hold a value for a short period. Temporaries are commonly created when returning values from functions by value.

#### Example

```cpp
#include <iostream>

int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input; // returns a copy of input
}

int main()
{
    std::cout << getValueFromUser() << '\n'; // where is the return value stored?
    return 0;
}
```

#### Key Points

- Return by value creates a temporary object to hold the return value.
- Temporary objects have no scope (no identifier).
- They are destroyed at the end of the full expression in which they are created (before the next statement).
- If a temporary is used to initialize a variable, the variable is initialized before the temporary is destroyed.
- Modern C++ (C++17 and later) often optimizes away unnecessary temporaries (copy elision, RVO).

In the example:
- The return value of `getValueFromUser()` is stored in a temporary, which is then passed to `std::cout`. The temporary is destroyed after the output statement.

