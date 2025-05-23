# Compound Types: References and Pointers
### Lvalues and Rvalues
| Expression      | Description                                                   |
| --------------- | ------------------------------------------------------------- |
| `lvalue`        | Refers to a named object (can appear on the left side of `=`) |
| `rvalue`        | Temporary value (can appear only on the right side of `=`)    |
| Lvalue → Rvalue | Allowed implicitly                                            |
| Rvalue → Lvalue | ❌ Not allowed                                                 |

### Reference to Lvalues and Rvalues
#### Lvalues
- refs. are made using an `&`.
```cpp
// regular types
int        // a normal int type (not an reference)
int&       // an lvalue reference to an int object
double&    // an lvalue reference to a double object
const int& // an lvalue reference to a const int object
```
- An lvalue reference var is a var that acts as a ref to an lvalue
```cpp
#include <iostream>

int main()
{
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x

    std::cout << x << '\n';  // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)

    // NOTE: Here's ref is an alias to x
    // - Therefore, any change made to x is also done to ref (same vice-versa)
    return 0;
}
```
- References can’t be reseated (changed to refer to another object)
- Refernces have the same scopes as normal variables.
- Because references aren’t objects, they can’t be used anywhere an object is required (e.g. you can’t have a reference to a reference, since an lvalue reference must reference an identifiable object)

- You can make const references and refer to const or non lvalue variables. 
    - If you const ref to non-const variable, then you can modify it by only the non-const variable. Can't modify thru the ref.

#### Pass-by-reference
- Unlike pass-by-value (simple types e.g. int), making copies is expensive for compound types.
- Pass by reference avoids expensive copies and gives direct access to the original argument.
```cpp
#include <iostream>

void printAddresses(int val, int& ref)
{
    std::cout << "The address of the value parameter is: " << &val << '\n';
    std::cout << "The address of the reference parameter is: " << &ref << '\n';
}

int main()
{
    int x { 5 };
    std::cout << "The address of x is: " << &x << '\n';
    printAddresses(x, x);

    return 0;
}
/* Expected output:
The address of x is: 0x7ffd16574de0
The address of the value parameter is: 0x7ffd16574de4
The address of the reference parameter is: 0x7ffd16574de0
*/
// NOTE: We can see that the arg has a diff address than the val param, meaning the val param is a diff object. 
```
- You can also use pass by ref to modify the original variable inside a function. Not smth u could do with pass-by-value, becaue the arg and param are diff objects.

- *LIMITATION*: Can only pass modifiable Lvalues to non-const ref. params.

### What is const lvalue reference?
A const reference can refer to:
- modifiable variables
- constants
- temporary values (rvalues) like literals (5, 'A', etc.)

#### Why use const reference?
- Avoids copying the argument (saves memory/time).
- Guarantees the function won't change the argument.
- Can accept more types of values than non-const references.

#### When to use it?
Use const reference for:
- Large objects (like std::string, custom classes).
- When you don't want to modify the original data.
- Use non-const reference only if the function needs to change the value.

#### What about temporary values (rvalues)?
- const references can bind to temporaries.
- Example: `printRef(5);` is okay if printRef takes a `const int&`.

#### Type conversion with const references
- A const reference can bind to a different but convertible type (e.g., int to double).
- Creates a temporary of the expected type.
- This might make an unwanted copy, so be cautious.

#### Mixing value and reference parameters
You can mix them in one function:
```cpp
void func(int a, int& b, const std::string& c);
```

#### Rule of thumb:
- 📦 Fundamental types (int, char, double): Pass by value (cheap to copy).
- 📦 Class types (like std::string, std::vector): Pass by const reference (can be expensive to copy).
- ❓ Not sure? Use const reference – it's safer and usually better.

#### Is copying always bad?
No, sometimes copying is faster to access and easier to optimize than reference (depends on object size and type).

#### Cheap to copy = good to pass by value
A type is cheap to copy if:
- Size is less than or equal to 2 pointers.
- It has no setup cost (like memory allocation, file handling).

#### Special case: std::string_view
Prefer std::string_view over const std::string&:
- It accepts both std::string and C-style strings ("hello").
- No copying needed, even for substrings.
