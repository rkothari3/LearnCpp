/*
QUESTION 3: Name two reasons why we prefer to pass arguments by const reference instead of by non-const reference whenever possible.

- A non-const reference parameter can be used to modify the value of the argument. If we do not need this ability, it's better to pass by const reference so that we don't accidentally modify the argument.

- A non-const reference parameter can only accept a modifiable lvalue as an argument. A const reference-parameter can accept a modifiable lvalue, a non-modifiable lvalue, or an rvalue as an argument.

*/
// EXAMPLE:
#include <iostream>

// Function with non-const reference parameter - can modify the argument
void modifyValue(int& value) {
    value *= 2; // Modifies the original value
}

// Function with const reference parameter - cannot modify the argument
void printValue(const int& value) {
    // value *= 2; // Error! Cannot modify a const reference
    std::cout << value << '\n';
}

int main() {
    // With modifiable lvalue
    int x = 5;
    modifyValue(x);  // Works - x becomes 10
    printValue(x);   // Works - prints 10
    
    // With non-modifiable lvalue
    const int y = 7;
    // modifyValue(y);  // Error! Cannot bind non-const reference to const value
    printValue(y);   // Works - const reference can accept const value
    
    // With rvalue
    // modifyValue(3 + 4);  // Error! Cannot bind non-const reference to rvalue
    printValue(3 + 4);  // Works - const reference can accept rvalue
    
    return 0;
}

/* 
QUESTION 4: What is the difference between a const pointer and a pointer-to-const?

- A const pointer is a pointer whose address can not be changed (it cannot be re-pointed at some other object). However, the value of the object being pointed to can be changed.

- A pointer-to-const is a pointer that is pointing at an object whose value can't be changed through the pointer. However, the pointer can be re-pointed at another object.
*/

// Example demonstrating the difference
#include <iostream>

int main() {
    int value1 = 5;
    int value2 = 10;
    
    // Pointer-to-const (pointer to const int)
    const int* ptr1 = &value1;
    // *ptr1 = 7;      // Error: cannot modify a const object
    ptr1 = &value2;     // OK: can change where the pointer points
    
    // Const pointer (const pointer to int)
    int* const ptr2 = &value1;
    *ptr2 = 7;         // OK: can modify the pointed-to value
    // ptr2 = &value2; // Error: cannot change a const pointer
    
    // Const pointer to const (const pointer to const int)
    const int* const ptr3 = &value1;
    // *ptr3 = 7;      // Error: cannot modify a const object
    // ptr3 = &value2; // Error: cannot change a const pointer
    
    std::cout << "value1: " << value1 << '\n';  // Prints 7 (modified through ptr2)
    std::cout << "value2: " << value2 << '\n';  // Prints 10
    
    return 0;
}
