# C++17 Features and Switch Statements

## Constexpr If Statement

C++17 introduces the `constexpr if` statement, which requires the conditional to be a constant expression. The conditional in a `constexpr if` statement is evaluated at compile-time.

- If the constexpr conditional evaluates to true, the entire if-else block is replaced by the true-statement.
- If it evaluates to false, the entire if-else block is replaced by the false-statement (if it exists) or by nothing (if there is no else).

> Favor `constexpr if` statements over non-`constexpr if` statements when the conditional is a constant expression.

## Switch Statements

Switch statements in C++ behave similarly to those in Java.

### Switch Fall-Through

```cpp
#include <iostream>
using namespace std;

int main() {
    int option = 1;

    // Demonstrating fall-through behavior:
    switch (option) {
        case 1:
            cout << "Case 1 executed" << endl;
            // Fall-through: No break here, so execution continues into case 2.
        case 2:
            cout << "Case 2 executed" << endl;
            break;
        case 3:
            cout << "Case 3 executed" << endl;
            break;
        default:
            cout << "Default case executed" << endl;
            break;
    }
    
    return 0;
}
// Expected Output:
// Case 1 executed
// Case 2 executed
```

### Goto Statements
- Goto statements can be used to jump to a specific label within a function.
- Avoid using these, unless no other alternative is better at making code readable.


### Loops
### While-loops
while (condition)
    statement;
### Do-while loops
do {
    statement;
} while (condition);
- Always execute at least once.
### For-loops
for (init-statement; condition; end-expression)
   statement;
- The init-statement is executed once before the loop starts.
```cpp
#include <iostream>

int main()
{
	for (char c{ 'a' }; c <= 'e'; ++c) // outer loop on letters
	{
		std::cout << c; // print our letter first

		for (int i{ 0 }; i < 3; ++i) // inner loop on all numbers
			std::cout << i;

		std::cout << '\n';
	}

	return 0;
}
```

### Break and Continue
- `break` statement: Exits the loop immediately.
- `continue` statement: Skips the current iteration and continues with the next iteration of the loop.
- Break vs. Return:
  - `break` exits the loop, while `return` exits the function.

---

## Generating Random Numbers in C++

### Basics

- Use the `<random>` header for modern, flexible random number generation.
- Avoid using `rand()` and `srand()` (old C-style, less random and less safe).

### Steps to Generate Random Numbers

1. **Include the header:**
   ```cpp
   #include <random>
   ```
2. **Create a random engine:**  
   (e.g., `std::mt19937` is a good default engine)
   ```cpp
   std::mt19937 rng{ std::random_device{}() }; // random seed
   ```
3. **Choose a distribution:**  
   - For integers: `std::uniform_int_distribution`
   - For floating-point: `std::uniform_real_distribution`
   ```cpp
   std::uniform_int_distribution<int> dist(1, 6); // range [1, 6]
   ```

4. **Generate a number:**
   ```cpp
   int randomNumber = dist(rng);
   ```

### Example: Rolling a Die

```cpp
#include <iostream>
#include <random>

int main() {
    std::mt19937 rng{ std::random_device{}() }; // seed the engine
    std::uniform_int_distribution<int> dist(1, 6); // numbers 1-6

    int roll = dist(rng);
    std::cout << "You rolled: " << roll << '\n';
    return 0;
}
```
**Expected Output:**  
You rolled: 4  
*(Output will vary each run)*

### Example: Random Floating-Point Number

```cpp
#include <iostream>
#include <random>

int main() {
    std::mt19937 rng{ std::random_device{}() };
    std::uniform_real_distribution<double> dist(0.0, 1.0); // [0.0, 1.0)

    double num = dist(rng);
    std::cout << "Random number: " << num << '\n';
    return 0;
}
```
**Expected Output:**  
Random number: 0.374829  
*(Output will vary each run)*

### Notes

- Always create the engine (`std::mt19937`) only once, not inside a loop.
- You can change the range by adjusting the distribution's parameters.
- For reproducible results (e.g., debugging), you can seed the engine with a fixed value:
  ```cpp
  std::mt19937 rng{ 123 }; // always produces the same sequence
  ```

---


