# Chapter 11: Function Overloading and Templates
### Function Overloading
```cpp
#include <iostream>

int add(int x, int y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}

int main() {
    std::cout << add(1, 2) << '\n';        // calls add(int, int), prints 3
    std::cout << add(1.2, 3.4) << '\n';    // calls add(double, double), prints 4.6
    return 0;
}
```
- An ambiguous call to an overloaded function occurs when the compiler cannot determine which version of the function to call.
```cpp
// Example of ambiguous call
#include <iostream>
int add(int x, int y) {
    return x + y;
}
double add(double x, double y) {
    return x + y;
}
int main() {
    std::cout << add(1, 2.5) << '\n'; // ambiguous call
    return 0;
}
```
- To resolve ambiguity, you can use a cast to specify the type explicitly.
```cpp
#include <iostream>
int add(int x, int y) {
    return x + y;
}
double add(double x, double y) {
    return x + y;
}
int main() {
    std::cout << add(1, 2.5) << '\n'; // ambiguous call
    std::cout << add(static_cast<int>(1), static_cast<int>(2.5)) << '\n'; // resolves ambiguity
    return 0;
}
```
### = delete specifier
- The `= delete` specifier is used to disable a function or constructor, preventing it from being called.
```cpp
#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

int main()
{
    printInt(97);   // okay

    printInt('a');  // compile error: function deleted
    printInt(true); // compile error: function deleted

    printInt(5.0);  // compile error: ambiguous match

    return 0;
}
```
### Default Arguments
- Default arguments are values that are automatically passed to a function if the caller does not provide them.
```cpp
#include <iostream>

void print(int x=10, int y=20, int z=30)
{
    std::cout << "Values: " << x << " " << y << " " << z << '\n';
}

int main()
{
    print(1, 2, 3); // all explicit arguments
    print(1, 2); // rightmost argument defaulted
    print(1); // two rightmost arguments defaulted
    print(); // all arguments defaulted

    return 0;
}
/*
Output:
Values: 1 2 3
Values: 1 2 30
Values: 1 20 30
Values: 10 20 30
*/
```cpp
- Default arguments with Forward declaration
```cpp
#include <iostream>

void print(int x, int y); // forward declaration, no default argument

int main()
{
    print(3); // compile error: default argument for y hasn't been defined yet

    return 0;
}

void print(int x, int y=4)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
```
- Default arguments with Function Overloading:
```cpp
#include <iostream>
void print(int x, int y=4) {
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
void print(double x, double y=4.0) {
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
int main() {
    print(3); // calls print(int, int)
    print(3.5); // calls print(double, double)
    return 0;
}