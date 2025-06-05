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
