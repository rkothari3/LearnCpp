# Chapter 9: Exceptions and Error Handling

Branch coverage measures the percentage of branches executed during testing. Both the affirmative and negative cases are counted separately.

## Chapter 9 Review

**Scope Creep:**  
Occurs when a project’s capabilities expand beyond the originally intended scope.

**Software Verification:**  
The process of testing whether the software works as expected in all cases.

- **Unit Testing:**  
    Tests a small portion of code (typically a function or call) in isolation to verify a particular behavior. Unit test frameworks help organize these tests.

- **Integration Testing:**  
    Ensures that multiple units work together properly.

**Code Coverage:**  
Indicates what percentage of the source code is executed during tests.

- **Statement Coverage:**  
    The percentage of statements exercised by tests.
    
- **Branch Coverage:**  
    The percentage of branches (decision points) exercised.
    
- **Loop Coverage:**  
    Tests loops for 0, 1, and 2 iterations to ensure proper behavior.

**Happy and Sad Paths:**

- **Happy Path:**  
    The execution path when there are no errors.
    
- **Sad Path:**  
    The path taken when an error or failure state occurs.

**Error Handling:**

- **Non-Recoverable Errors (Fatal Errors):**  
    Errors so severe that the program cannot continue running.
    
- A robust program effectively handles error cases.

**Buffers:**  
Temporary memory storage used while moving data from one place to another.

**Input Validation:**  
The process of checking whether user input meets the program's expectations.

**Error Streams:**  
`std::cerr` is used specifically for error messages, similar to how `std::cout` is used for regular output.

**Program Contracts:**

- **Precondition:**  
    A condition that must be true before a segment of code executes.
    
- **Invariant:**  
    A condition that remains true during the execution of a component.
    
- **Postcondition:**  
    A condition that must be true after the execution of code.

**Assertions:**

- An assertion is an expression that should always be true unless a bug exists.
    
- In C++, runtime assertions are typically implemented using the `assert` macro and are usually disabled in non-debug builds.
    
- **static_assert:**  
    A compile-time assertion.

*Note:*  
Use assertions to document logically impossible scenarios, while error handling is reserved for possible error conditions.