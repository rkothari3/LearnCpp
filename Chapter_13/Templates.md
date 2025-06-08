# Chapter 13.13 - 13.15
## 13.13
### Recall: Function Templates
- Instead of having to repeat nearly indentical code we could use templates.
```cpp
// INEFFICENT
int max(int x, int y) { return (x < y) ? y : x; }
double max(double x, double y) { return (x < y) ? y : x; }

// EFFICIENT
template <typename T>
T max(T x, T y) { return (x < y) ? y : x; }
```

### Same problem with Structs
- The same problem can occur with structs.
```cpp
struct Pair {
    int first;
    int second;
};
struct Pair {
    double first;
    double second;
};

// THIS WON'T WORK
// - Two structs cant have the same name.
// INSTEAD, use class templates.
template <typename T>
struct Pair {
    T first;
    T second;
};

// To use
Pair<int> p1{5, 6};
Pair<double> p2{1.2, 3.4};

// Class templates with Multiple Types
template <typename T, typename U>
struct Pair {
    T first;
    U second;
};

Pair<int, double> p1{1, 2.5};
Pair<std::string, char> p2{"Raj", 'R'};

// You can also write a template function
template <typename T, typename U>
void print(Pair<T, U> p) {
    std::cout << "[" << p.first << ", " << p.second << "]";
}


// We can also use the standard library instead: std::pair
// C++ provides this in utlility

#include <utility>

std::pair<int, double> p{1, 2.5};
std::cout << p.first << " " << p.second;
```

## 13.14
In C++ 17, CTAD was introduced. This lets the compiler figure out the template params. for you based on how you intialize the object.
```cpp
// Without CTAD
std::pair<int, int> p1{1, 2};  // You write the types manually

// With CTAD (NOTE: Only works when you don't specify template args)
std::pair p2{1, 2};  // Compiler deduces it's std::pair<int, int>
```

## 13.15
1. Basic Type Alias (non-template)
```cpp
template <typename T>
struct Pair {
    T first{};
    T second{};
};

using IntPair = Pair<int>; // This is just like saying: typedef Pair<int> IntPair;

// Here, IntPair is an alias for Pair<int>.
// Therefore, now you can write:
IntPair p{1 ,2};
```

2. Alias Template
- Use this instead when suppose you don't want the type to be always int but still want something shorter and simpler.
- Useful when working with larger, complex types.
```cpp
// SIMPLE EXAMPLE
template <typename T>
using Coord = Pair<T>;  // Coord is a parameterized alias for Pair<T>

Coord<int> p1{1, 2};  // Same as Pair<int>
Coord<double> p2{1.2, 2.3};  // Same as Pair<double>
Coord p3{1, 2};  // Deduces Coord<int> if CTAD is possible
```

3. Using Alias Templates in Functions
- Must pass explicit types to alias templates in function parameters.
```cpp
template <typename T>
void print(const Coord<T>& c) {
    std::cout << c.first << ' ' << c.second << '\n';
}

// NOTE: CTAD don't work here. 
// Thus, void print(const Coord& c);  // error: template argument missing
```