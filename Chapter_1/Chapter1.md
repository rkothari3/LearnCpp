# C++ Basics Chapter 1

### Statements and the structure of a C++ program

- A statement is an instruction in a computer program that tells the computer to perform an action.
- A function is a collection of statements that executes sequentially.
- The main() function must be in all programs.
- Single line comments -> // or Multi-line comments -> /\* \*/

```cpp
#include <iostream> // C++ library for input/output from/to console.

int main()
{
    /*
    std::cout (which stands for “character output”) and the << operator allow us to display information on the console.
    */
    std::cout << "Hello world!";
    return 0;
}
```

```cpp
#include <iostream>
int main() {
    // The values below are literals, they are placed directly into src code.
    // - Literals are read-only however, meaning values can't be modified.
    std::cout << 12;
    std::cout << 'A';
    std::cout << "Hello";

    return 0;
}
```

- Objects in C++ can be used to store and retrieve values, and their benefit is that we don't have to worry about where in memory those objects are actually placed.
- Data type of an object must be known at compile-time (so compiler knows how much memory the object requires.)

```cpp
#include <iostream>
int main() {
    int width, height;
    width = 11;
    height = 10;

    int total = width * height;

    std::cout << total;
}
```

**Intializing Variable**

```cpp
int a; // default intialization (no initalizer value)
int b = 5; // copy-intilaization (using =)
int c(6); // direct-intialization (using parathesis)
int d{7}; // direct-list-initialization (using curly braces, preferred)
int e{}; // value-initialization (sets to 0)
```

- You want to using curly braces becuase it prevents accidental mistakes, like putting a decimal value into an integer (which would lose data)
  **Ex:**

```cpp
int w1 { 4.5 }; // Compile Error! Can't put 4.5 into an int using braces.
int w2 = 4.5;   // Okay, but w2 will just be 4 (decimal part lost).
/*
* Note that this restriction on narrowing conversions only applies to the list-initialization, not to any subsequent assignments to the variable.
*/
w1 = 4.5; // okay bc copy-assignment allows narrowing from 4.5 to 4.
```

- Best to use direct-list intialization or value-intialization.

- Expressions are used when we want the program to calculate a value.
