# Chapter_7 Compound Statements
- Code blocks are created by using {---}
- While functions can't be nested in C++, these code blocks can be nested.
- These block are often used in conditional scenarios like if statements and nested if statements.

### User-defined namespaces and the scope resolution operator (::)
```cpp
#include <iostream>

namespace Foo // define a namespace named Foo
{
    // This doSomething() belongs to namespace Foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Goo // define a namespace named Goo
{
    // This doSomething() belongs to namespace Goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << Foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace Foo
    std::cout << Goo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace Goo
    return 0;
}
```

### Local Variables
- They have a block scope.
```cpp
int main()
{
    // i and d enter local scope
    int i{1}; 
    double d{5.0};

    return 0;
}
    // i and d out of scope here
```
- All variable names within a scope must be unique.

### Global Variables
- By convention, global variables are declared at the top of the file.
```cpp
#include <iostream>
double gravity{9.8}; // Can be used anywhere in the file
void getGravity()
{
    gravity = 11;
    return gravity;
}
int main()
{
    getGravity();

    gravity = 10;
}
```
- Best practice to define global variables inside a namespace rather than in the global namespace.
```cpp
#include <iostream>

namespace Foo // Foo is defined in the global scope
{
    int g_x {}; // g_x is now inside the Foo namespace, but is still a global variable
}

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    Foo::g_x = 3;
    std::cout << Foo::g_x << '\n';
}

int main()
{
    doSomething();
    std::cout << Foo::g_x << '\n';

    // global variables can be seen and used everywhere in the file
    Foo::g_x = 5;
    std::cout << Foo::g_x << '\n';

    return 0;
}
```
- Created when the program starts, and destroyed after the main block. Meaning they have static duration.
- Best practice: Consider using a “g” or “g_” prefix when naming global variables (especially those defined in the global namespace), to help differentiate them from local variables and function parameters.

- Constand global variables:
```cpp
#include <iostream>

const int g_x;     // error: constant variables must be initialized
constexpr int g_w; // error: constexpr variables must be initialized

const int g_y { 1 };     // const global variable g_y, initialized with a value
constexpr int g_z { 2 }; // constexpr global variable g_z, initialized with a value

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';
}

int main()
{
    doSomething();

    // global variables can be seen and used everywhere in the file
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';

    return 0;
}
// g_y and g_z goes out of scope here
```

### Variable Shadowing (name hiding)

**What it is:**  
An inner-scope declaration with the same name as an outer one hides (“shadows”) the outer variable until its block ends.

#### Local Shadowing

```cpp
int main() {
  int x = 5;        // outer x
  {
    std::cout << x;   // prints 5
    int x = 10;       // shadows outer x
    std::cout << x;   // prints 10
  }
  std::cout << x;     // prints 5
}
```

#### Global Shadowing

```cpp
int x = 5;          // global x
int main() {
  int x = 7;        // shadows global x
  ++x;              // local x = 8
  --::x;            // global x = 4
  std::cout << x << " " << ::x; // “8 4”
}
```

### Internal vs. External Linkage
- Note: Linkage is not the same as scope.
- Scope: region of the program where an identifier can be accessed. It is a compile-time concept.
    - Ex: block scope, function scope, file scope, class scope.
- Linkage: determines whether the same identifier in different scopes refers to the same entity. It is a compile-time and link-time concept.
    - Internal linkage: a variable or function accessible only within the file it is defined.
        - To make a non-constant global variable internal, we use the static keyword. Const and constexpr are internal linkage by default.
        - Functions although default to external linkage, they can be made internal by adding the static keyword.
        - Useful for local helper variables and functions.
    - External Linkage: a variable or function accesible in multiple files.
        - Done using a extern keyword.
        - Global shared rss. 

```cpp
// file1.cpp
#include <iostream>

// Definition of a non-const global variable.
// Non-const globals have external linkage by default.
int g_count = 10;

// Optional: A function to modify g_count.
void increment() {
    ++g_count;
}

// file2.cpp
#include <iostream>

// Forward declaration of the external variable.
// This tells the compiler that g_count is defined elsewhere.
extern int g_count;

// Forward declaration of the function defined in file1.cpp
void increment();

int main() {
    std::cout << "Initial count: " << g_count << '\n';  // prints 10
    increment();
    std::cout << "After increment: " << g_count << '\n'; // prints 11
    return 0;
}

```

### Static Local Variables
- When applied to a global variable, the static keyword defines the global variable as having internal linkage, meaning the variable cannot be exported to other files.
- When applied to a local variable, the static keyword defines the local variable as having static duration, meaning the variable will only be created once, and will not be destroyed until the end of the program.

### Summary

### Variable Types Summary

| Type | Example | Scope | Duration | Linkage | Notes |
|------|---------|-------|----------|---------|-------|
| Local variable | int x; | Block | Automatic | None | |
| Static local variable | static int s_x; | Block | Static | None | |
| Dynamic local variable | int* x { new int{} }; | Block | Dynamic | None | |
| Function parameter | void foo(int x) | Block | Automatic | None | |
| Internal non-const global variable | static int g_x; | Global | Static | Internal | Initialized or uninitialized |
| External non-const global variable | int g_x; | Global | Static | External | Initialized or uninitialized |
| Inline non-const global variable (C++17) | inline int g_x; | Global | Static | External | Initialized or uninitialized |
| Internal constant global variable | constexpr int g_x { 1 }; | Global | Static | Internal | Must be initialized |
| External constant global variable | extern const int g_x { 1 }; | Global | Static | External | Must be initialized |
| Inline constant global variable (C++17) | inline constexpr int g_x { 1 }; | Global | Static | External | Must be initialized |


### Unamed (Anonymous) Namespaces
- namespace without a name. Everything inside only accessible within the same src file.
- Use unnamed namespaces for file-local code, but never in header files, as this may cause multiple definitions and linkage errors.
```cpp
#include <iostream>

namespace // unnamed namespace
{
    void doSomething() // only accessible in this file
    {
        std::cout << "v1\n";
    }
}

int main()
{
    doSomething(); // OK: accessible here
    return 0;
}

```

### Inline Namespaces
- named namespace declared with the inline keyword.
- typically used for versioning code, letting you provide different versions of functions or types without breaking old code
```cpp
#include <iostream>

inline namespace V1 // inline namespace
{
    void doSomething()
    {
        std::cout << "V1\n";
    }
}

namespace V2 // normal namespace
{
    void doSomething()
    {
        std::cout << "V2\n";
    }
}

int main()
{
    V1::doSomething(); // Calls V1 version
    V2::doSomething(); // Calls V2 version
    doSomething();     // Calls the inline version (V1)
    return 0;
}

// NOTE: If u want V2 to be the defaut, make V2 the inline namespace
```

### Mixing Inline and Unnamed Namespaces
- You can combine both, but it’s usually clearer to nest an unnamed namespace inside an inline namespace. This way, you get internal linkage (file-local visibility) and versioning
```cpp
#include <iostream>

namespace V1
{
    void doSomething() { std::cout << "V1\n"; }
}

inline namespace V2
{
    namespace // unnamed namespace
    {
        void doSomething() // internal linkage
        {
            std::cout << "V2\n";
        }
    }
}

int main()
{
    V1::doSomething(); // V1
    V2::doSomething(); // V2
    doSomething();     // V2 (inline version)
    return 0;
}

```

Recap:
- Unnamed namespaces: Use for file-local code; avoid in headers.
- Inline namespaces: Use for versioning APIs/libraries; does not affect linkage.
- Mixing: Nest unnamed inside inline for versioned, file-local code.


# Qualified and unqualified names
- A qualified name is a name that includes an associated scope (e.g. std::string). An unqualified name is a name that does not include a scoping qualifier (e.g. string).

