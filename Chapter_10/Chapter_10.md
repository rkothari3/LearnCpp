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

