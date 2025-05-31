# Pointers -> WTF IS THAT!!!
- Pointers hold memory address as its value.
- Naming convention (type*) -> (e.g. int*)

#### Pointer initialization
```cpp
int main()
{
    int x{5};

    int* ptr; // an unintialized pointer (holds a garbage address)
    int* ptr2{}; // an null pointer
    int* ptr3{&x}; // a pointer intialized with the address of variable x
}
```
- The type of object being referred to cannot be different from the type of pointer.

### Pointers and assignment
```cpp
#include <iostream>

int main()
{
    int x{5};
    int* ptr{&x}; // ptr intialized to point x

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (x's address)

    // TO CHANGE:
    int y{6};

    ptr = &y; // change ptr to point at y

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (y's address)

    return 0;
}
```

### Size of Pointers
- The size of the pointer is always the same. This is because a pointer is just a memory address, and the number of bits needed to access a memory address is constant.
```cpp
#include <iostream>

int main() // assume a 32-bit application
{
    char* chPtr{};        // chars are 1 byte
    int* iPtr{};          // ints are usually 4 bytes
    long double* ldPtr{}; // long doubles are usually 8 or 12 bytes

    std::cout << sizeof(chPtr) << '\n'; // prints 4 (4bytes -> 32bit)
    std::cout << sizeof(iPtr) << '\n';  // prints 4
    std::cout << sizeof(ldPtr) << '\n'; // prints 4

    return 0;
}
```

### Dangling Pointers
- A dangling pointer is a pointer that is holding the address of an object that is not longer often because it had been destroyed.
- Deref. a dangling pointer will lead to undefined behavior as you are trying to access an object that is no longer valid.
```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    int* ptr{ &x };

    std::cout << *ptr << '\n'; // valid

    {
        int y{ 6 };
        ptr = &y;

        std::cout << *ptr << '\n'; // valid
    } // y goes out of scope, and ptr is now dangling

    std::cout << *ptr << '\n'; // undefined behavior from dereferencing a dangling pointer

    return 0;
}
```

### Null Pointers
```cpp
#include <iostream>

int main()
{
    int* ptr {};

    int x {5};

    ptr = &x;

    std::cout << *ptr << '\n';
}
```
- Use the nullptr keyword for intialization, assignment, or passing a null pointer to a function.
```cpp
#include <iostream>

int main()
{
    int* ptr {nullptr}; // Explicit intialize nullptr

    int value {5};

    int* ptr2 {&value}; // ptr2 is valid ptr

    ptr2 = nullptr; // Assignment ptr2 to make the pointer a nullptr
}