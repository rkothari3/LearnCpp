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
- Created when the program starts, and destroyed after the main block.
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
