# Compound Types: Enums and Structs
- Program-defined types: necessary when built-in types aren't sufficient to represent complex data.
- C++ offers two main categories for creating program-defined types:
    - Enumerated types: unscoped and scoped enumerations
    - Class types: structs, classes, and unions
```cpp
// Convention: Program-defined types also starting letter is capital.
struct Fraction {
    int numerator{};
    int denominator{};
}; // Type Defs. must end with semicolon.

int main() {
    Fraction f {3, 4};
}
```

### Enums
- Programmer defined
```cpp
enum Pet
{
    cat,
    dog,
    pig,
    whale,
};

enum Color
{
    black,
    red,
    blue,
};

int main()
{
    Pet myPet { black }; // compile error: black is not an enumerator of Pet
    Color shirt { pig }; // compile error: pig is not an enumerator of Color

    return 0;
}
```

### Converting an enum to a string
- By default printing an enum value results in a integer output.
```cpp
enum Color {
    black,
    red,
    blue
};
Color shirt{blue};

std::cout << shirt << '\n';
```

Solution: you can write a function that takes an enum value and returns its name as a string.
```cpp
#include <string_view>
enum Color {
    black,
    red,
    blue
}
constexpr std::string_view getColorName(Color color) {
    switch (color) {
        case black:
            return "black";
        case blue:
            return "blue";
        case red:
            return "red";
    }
}

std::cout << "Your shirt is " << getColorName(shirt) << '\n'; // Prints: Your shirt is blue
```
- However this is still not optimal. We have to repeat the function name more and more and this adds more clutter code. 

### Introduction to operator overloading
- To make this more optimal, overload the operator<<
```cpp
#include <iostream>
#include <string_view>

std::ostream& operator<<(std::ostream& out, Color color) {
    // std::ostream& out is the output stream
    // The return/param types are references (to prevent copies)
    out << getColorName(color);
    return out;
}

Color shirt{ blue };
std::cout << "Your shirt is " << shirt << '\n';
```

### Scoped enumerations
- Unscoped enums as seen above are those that are in the global namespace.
- scoped enums have a scope (duh). These are also called enum class

```cpp
#include <iostream>

int main()
{
    enum class Color
    {
        red,
        blue,
    };

    enum class Fruit
    {
        banana,
        apple,
    };

    Color color { Color::red }; // note: red is not accessible so we have to use Color::red. Same for fruit below

    Fruit fruit { Fruit::banana }; // note: banana is not directly accessible, we have to use Fruit::banana

    std::cout << Color::red; // Will result in Compile Error

    if (color == fruit) // compile error: the compiler doesn't know how to compare different types Color and Fruit
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";

    return 0;
}
```
- To compare different scoped enum types, you need to cast them to a common type.

```cpp
#include <iostream>

enum class Color
{
    red,
    blue,
};

enum class Fruit
{
    banana,
    apple,
};

int main()
{
    Color color { Color::red };
    Fruit fruit { Fruit::banana };

    if (static_cast<int>(color) == static_cast<int>(fruit))
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";

    return 0;
}
```
### More on structs
```cpp
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe {};
    joe.id = 14;
    joe.age = 32;
    joe.wage = 60000.0;

    Employee frank {};
    frank.id = 15;
    frank.age = 28;
    frank.wage = 45000.0;

    // Add their ages
    int totalAge = joe.age + frank.age;
    std::cout << "Joe and Frank have lived " << totalAge << " total years\n";

    // Compare wages
    if (joe.wage > frank.wage)
        std::cout << "Joe makes more than Frank\n";
    else if (joe.wage < frank.wage)
        std::cout << "Joe makes less than Frank\n";
    else
        std::cout << "Joe and Frank make the same amount\n";

    // Give Frank a raise
    frank.wage += 5000.0;

    // It's Joe's birthday!
    ++joe.age;

    return 0;
}
```
### Struct aggregate intialization
- NOTE: struct members are not initialized by default.
- In C++, an aggregate is a specific type of data structure that has no user-defined constructors, no private or protected non-static data members, no base classes, and no virtual functions.
- Structs with only public data members are considered aggregates. Thus, they can be initialized using aggregate initialization.

- Forms of agregate initialization:
    -  Copy-list initialization: Employee frank = { 1, 32, 60000.0 };
    - List initialization (preferred): Employee joe { 2, 28, 45000.0 };
    - Direct initialization with parentheses (C++20): Employee robert(3, 45, 62500.0);