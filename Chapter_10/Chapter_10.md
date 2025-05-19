# Chapter 10

- **Implicit type conversion:** Automatically performed by the compiler when needed.
- **Explicit type conversion:** Requested by the programmer using a cast operator (e.g., static_cast).
- **Promotions in C++:** Automatic conversions that change smaller (narrower) types into larger (wider) types so the computer can handle them more efficiently.

### Types of Promotions

- **Floating-Point Promotion:**  
    - Converting an integer to a floating-point type (float or double).
    - **Example:**
        ```cpp
        int x = 5;
        float y = x; // x is promoted to float
        ```
        
- **Integral Promotion:**  
    - Converting a smaller integer type (like char or short) to a larger integer type (like int or long).
    - **Example:**
        ```cpp
        char c = 'A';
        int i = c; // c is promoted to int
        ```
    - **Example:**
        ```cpp
        bool b = true;
        int i = b; // b becomes 0 (for false) or 1 (for true)
        ```

### Types of Numeric Conversions

There are five main kinds:

- **Between integral types:** Changing from one integer type to another (e.g., int to short, short to char, int to unsigned int).
- **Between floating-point types:** Changing from one floating-point type to another (e.g., double to float, double to long double).
- **Floating-point to integral:** Converting a floating-point number to an integer (e.g., double to int).
- **Integral to floating-point:** Converting an integer to a floating-point number (e.g., int to double).
- **To bool:** Converting any integer or floating-point value to a bool (0 or 0.0 becomes false; any other value becomes true).

Unlike promotions (which are always safe and don’t lose information), many numeric conversions can lose data or change the value in unexpected ways. There are three safety categories:

1. **Value-Preserving (Safe):**  
     The new type can represent all values of the original type.  
     *Example:* int to long, short to double. You can convert back and forth without losing information.

2. **Reinterpretive (Risky):**  
     The value might change, but no data is lost (usually with signed/unsigned types).  
     *Example:* Converting a negative int to unsigned int results in a large positive number.

3. **Lossy (Unsafe):**  
     Some information is lost during the conversion.  
     *Example:*  
     - Converting double to int (the fractional part is dropped)  
     - Converting double to float (precision is lost)  
     Converting back will not recover the original value.

#### Examples

- `int i = 3.5;` → i becomes 3 (the .5 is lost).
- `float f = 1.23456789;` → f becomes something like 1.23457 (some digits are lost).
- `unsigned int u = -5;` → u becomes a large number (because unsigned types cannot be negative).

#### What Can Go Wrong?

If you convert a value that’s too big or too small for the new type, you might encounter overflow or unexpected results. For example, assigning 30000 to a char (which can typically hold values from -128 to 127) can result in a strange value. Converting from a larger type to a smaller one (like double to float or int to char) can lead to a loss in precision or data.

#### When Are Conversions Okay?

- If you know the value will fit in the new type.
- If you don’t care about losing information (such as converting any non-zero number to true with bool).

### Narrowing Conversions
- If you need to perform a narrowing conversion, use a `static_cast` to convert it into an explicit conversion.
- Brace intializtion disallows narrowing conversions.
    - Example:
    ```cpp
    int main()
    {
        int i {3.5}; // won't compile
        return 0;
    }
    ```

- Use type deduction for your variables when the type of the object doesn’t matter.

- Use an explicit type when you require a specific type that differs from the type of the initializer, or when your object is used in a context where making the type obvious is useful.

## Chapter Review

The process of converting a value from one data type to another data type is called a type conversion.

**Implicit type conversion** (also called automatic type conversion or coercion) is performed whenever one data type is expected, but a different data type is supplied. If the compiler can figure out how to do the conversion between the two types, it will. If it doesn't know how, then it will fail with a compile error.

```cpp
double d = 3; // int 3 is implicitly converted to double 3.0
int x = 3.5;  // double 3.5 is implicitly converted to int 3 (with value loss)
```

The C++ language defines a number of built-in conversions between its fundamental types (as well as a few conversions for more advanced types) called **standard conversions**. These include numeric promotions, numeric conversions, and arithmetic conversions.

A **numeric promotion** is the conversion of certain smaller numeric types to certain larger numeric types (typically int or double), so that the CPU can operate on data that matches the natural data size for the processor. Numeric promotions include both integral promotions and floating-point promotions. Numeric promotions are value-preserving, meaning there is no loss of value or precision. Not all widening conversions are promotions.

```cpp
// Integral promotion
char c = 'a';
int i = c + 1; // 'a' is promoted to int before addition

// Floating-point promotion
float f = 3.14f;
double result = f * 2.0; // f is promoted to double before multiplication
```

A **numeric conversion** is a type conversion between fundamental types that isn't a numeric promotion. A **narrowing conversion** is a numeric conversion that may result in the loss of value or precision.

```cpp
// Numeric conversion (non-narrowing)
int i = 42;
long l = i; // int to long is a widening conversion

// Narrowing conversion
double d = 3.14159;
float f = d; // double to float may lose precision
int n = d;   // double to int loses the fractional part
```

In C++, certain binary operators require that their operands be of the same type. If operands of different types are provided, one or both of the operands will be implicitly converted to matching types using a set of rules called the **usual arithmetic conversions**.

```cpp
int i = 10;
double d = 3.14;
double result = i + d; // i is converted to double before addition
```

**Explicit type conversion** is performed when the programmer explicitly requests conversion via a cast. A cast represents a request by the programmer to do an explicit type conversion. C++ supports 5 types of casts: C-style casts, static casts, const casts, dynamic casts, and reinterpret casts. Generally you should avoid C-style casts, const casts, and reinterpret casts. `static_cast` is used to convert a value from one type to a value of another type, and is by far the most used cast in C++.

```cpp
double d = 3.14;
// static_cast - preferred way to do explicit conversions
int i1 = static_cast<int>(d);

// C-style cast - should generally be avoided
int i2 = (int)d;

// Function-style cast
int i3 = int(d);
```

**Typedefs and type aliases** allow the programmer to create an alias for a data type. These aliases are not new types, and act identically to the aliased type. Typedefs and type aliases do not provide any kind of type safety, and care needs to be taken to not assume the alias is different than the type it is aliasing.

```cpp
// typedef syntax
typedef unsigned int uint;
uint value1 = 42;

// type alias syntax (C++11 and later)
using Counter = unsigned int;
Counter value2 = 100;
```

The **auto keyword** has a number of uses. First, auto can be used to do type deduction (also called type inference), which will deduce a variable's type from its initializer. Type deduction drops const and references, so be sure to add those back if you want them.

```cpp
auto i = 42;      // i is deduced to be an int
auto d = 3.14;    // d is deduced to be a double
auto& ri = i;     // ri is a reference to i
const auto& rd = d; // rd is a const reference to d
```

Auto can also be used as a function return type to have the compiler infer the function's return type from the function's return statements, though this should be avoided for normal functions. Auto is used as part of the trailing return syntax.
 - Can't be used for function parameters.

```cpp
// Using auto as return type (C++14 and later)
auto add(int x, int y) {
    return x + y; // Return type is deduced as int
}

// Trailing return type syntax (C++11 and later)
auto multiply(int x, int y) -> int {
    return x * y;
}
```
