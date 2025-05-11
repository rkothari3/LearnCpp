# Chapter 6: Operators

---

> **Always use parentheses to disambiguate the precedence of operators if there is any question or opportunity for confusion.**

---

- The arithmetic operators all work like they do in normal mathematics.
- The remainder (`%`) operator returns the remainder from an integer division.

- The increment (`++`) and decrement (`--`) operators can be used to easily increment or decrement numbers.
  - **Avoid the postfix versions** of these operators whenever possible.

- **Beware of side effects**, particularly when it comes to the order that function parameters are evaluated.
  - *Do not use a variable that has a side effect applied more than once in a given statement.*

- The comma operator (`,`) can compress multiple statements into one.
  - *Writing the statements separately is usually better.*

---

### The Conditional Operator

The conditional operator (`?:`), also sometimes called the *arithmetic if operator*, is a ternary operator (an operator that takes 3 operands).

Given a conditional operation of the form:

```cpp
c ? x : y
```

- If conditional `c` evaluates to true, then `x` will be evaluated; otherwise, `y` will be evaluated.

**Parenthesizing the conditional operator:**

- Parenthesize the entire conditional operator when used in a compound expression (an expression with other operators).
- For readability, parenthesize the condition if it contains any operators (other than the function call operator).

---

- Relational operators can be used to compare floating point numbers.
  - *Beware using equality and inequality on floating point numbers.*

- Logical operators allow us to form compound conditional statements.