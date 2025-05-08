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

### Forward Declarations

- When we call a function before we have defined it, it results in a compilation error.
- There's two ways to resolve this: 1. Move up the function called. **2. Use Forward Declaration**.

Example:

```cpp
#include <iostream>

int add(int x, int y); // forward declaration of add() 

int main() 
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << 'n';
    // This no longer results in compilation error.
    return 0;
}
// If the declaration isn't defined correct, the compiler won't link it correctly, resulting in error.
int add(int x, int y)
{
    return x + y;
}
```

### Naming Collisions

- Occur when two things happen to have the same name in your code. 
- There are multiple ways to overcome this shortcoming.
    - Scope regions. Ex: You can have same name varibale in two different functions without resulting in naming collisions.
    - Namespaces: groups related names together so they don't conflict with names in other namespaces.
    - Curly Braces and indentation: Curly braces {} create new scope regions. Variables declared inside braces only exist there. Indenting code inside braces makes it easier to read and shows what's inside each scope.

### Pre-Processor

- A program that runs before the actual compilation of C++ code. 
- Scans your file looking for preprocessor directives. These diectives are instructions that begin a # symbol. Commonly used to handle directives like #include.
- When the preprocessor encounters #include <filename>, it replaces that line with the entire content of the specified file. This is commonly used to include header files (like <iostream>) which contain declarations for functions and objects.
- Also used in #define directive. This creates a macro, which is a rule for converting input text into replacement output text.
    - Object-like macros:
    ```cpp
    #define MY_NAME "Alex"
    // In the code, MY_NAME will be replaced by "Alex"
    std::cout << "My name is: " << MY_NAME << '\n'; 
    // Becomes std::cout << "My name is: " << "Alex" << '\n';
    ```
- Conditional Compilation preprocessor directives allow you to specify under what conditions something will or won't compile. Common ones include: #ifdef, #ifndef, and #endif.

### Header Files

Here's our completed header file:

add.h:

```cpp
// We really should have a header guard here, but will omit it for simplicity (we'll cover header guards in the next lesson)

// This is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!
```

In order to use this header file in main.cpp, we have to #include it (using quotes, not angle brackets).

main.cpp:

```cpp
#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
```

add.cpp:

```cpp
#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.

int add(int x, int y)
{
    return x + y;
}
```

### Header Files (.h, .hpp)

Header files are used in C++ to share declarations, like function prototypes, across multiple code files (.cpp). This avoids repeating these declarations manually in every file that needs them. When you use `#include <filename>` or `#include "filename"`, the preprocessor copies the entire content of the specified header file into your current file at that location. Use angle brackets (`< >`) for standard library headers (e.g., `<iostream>`) and double quotes (`" "`) for your own custom header files (e.g., `"myfunctions.h"`).

#### Best Practices

- Place only declarations (not definitions like full function bodies or global variable initializations) in header files to avoid errors related to the "one-definition rule" (ODR).
- Name header files to correspond with their associated source file (e.g., `utils.h` for `utils.cpp`).
- Have each `.cpp` file include its paired header file first.
- Explicitly include every header file that your code directly uses, rather than relying on it being included indirectly by another header.
- Avoid the inclusion of `.cpp` files.

### Header Guards

Header guards are crucial for preventing problems that arise when the same header file is included multiple times within a single `.cpp` file (often due to nested includes). If a header file were included multiple times without guards, any definitions or type declarations within it would be duplicated, leading to compilation errors.

#### Implementation

1. **Traditional Preprocessor Directives**: Wrap the header's content with `#ifndef`, `#define`, and `#endif`. Use a unique name (conventionally the header's filename in uppercase with underscores, e.g., `MY_HEADER_H`) to ensure the content is processed only once per file.

    ```cpp
    #ifndef MY_HEADER_H
    #define MY_HEADER_H
    // Content of the header file
    #endif
    ```

2. **`#pragma once`**: A simpler, non-standard but widely supported directive that instructs the compiler to include the header file only once.

    ```cpp
    #pragma once
    // Content of the header file
    ```

Header guards ensure that declarations and certain types of definitions (like class definitions or templates, which can safely reside in headers) are processed only once per compilation unit, even if the header is included multiple times directly or indirectly.

### How to Design Your First Programs

Effective program design involves planning before writing code. This approach helps in creating more manageable and robust software.

#### Design Steps

1. **Define the Goal**: Clearly state what the program is intended to do.
2. **Define Requirements**: List necessary features, constraints, and capabilities.
3. **Define Tools, Targets, and Backup Plan**: Consider the environment, tools (like IDEs), and always plan for code backup (version control systems like Git are recommended).
4. **Break Down Problems**: Decompose complex tasks into smaller, simpler sub-tasks. This hierarchy can map to functions within your program.
5. **Sequence Events**: Determine the order in which tasks or operations should occur.

#### Implementation Steps

1. **Outline `main()`**: Use the task sequence to sketch out the `main` function, often using comments or placeholder function calls initially.
2. **Implement Functions**: Develop each function individually, defining its inputs/outputs, writing its code, and testing it.
3. **Final Testing**: Thoroughly test the entire program once all parts are integrated.

#### Key Advice

- Start with simple goals and add features incrementally.
- Focus on one part of the program at a time.
- Test code frequently as you write it.
- Prioritize getting features working before perfecting code.
- Optimize for code maintainability rather than premature performance optimization.


