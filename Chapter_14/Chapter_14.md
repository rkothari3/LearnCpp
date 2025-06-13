# OOP in C++
- The problem with structs is that they're class invariants. Meaning that for a object to be valid it must always be true. 
- Therefore, with structs you can't reinforce rules about valid or invalid values. You're instead relying on the user to keep things valid.

- Classes resolve this issue. 
- Classes are a user-defined type, just like a struct - but with more tools for encapsulation, control, and safety.
```cpp
// Simple defined class

class Employee
{
    // member variables are often prefixed with a m_ <- short for 'member'
    int m_id{};
    int m_age{};
    double m_wage{};
};
```

- Classes can control who can access or modify.
```cpp

class Date
{
public: // makes members accessible outside the class
    int m_day{};
    int m_month{};
    int m_year{};
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

```

## Member Functions
- Member functions are functions that belong to a class or struct, allowing you to define actions that an object can perform.
- They keep properties (member variables) and actions (member functions) encapsulated together.

### Problem with Non-member Functions
- Separating properties and actions makes code less organized and connections less obvious.
```cpp
// Non-member function approach
struct Date
{
    int year{};
    int month{};
    int day{};
};

void print(const Date& date) // Separate from the Date struct
{
    std::cout << date.year << '/' << date.month << '/' << date.day;
}
```

### Member Function Solution
- Functions defined inside the class/struct definition.
```cpp
struct Date
{
    int year{};
    int month{};
    int day{};
    
    // Member function - action belongs with the data
    void print()
    {
        std::cout << year << '/' << month << '/' << day; // Direct access to members
    }
};

// Usage
Date today{2020, 10, 14};
today.print(); // Called using member selection operator
```

### Key Differences: Non-member vs Member Functions
1. **Declaration**: Member functions must be declared inside the class definition
2. **Calling**: Use dot operator (`.`) instead of passing object as parameter
3. **Access**: Direct access to member variables through the "implicit object"

### The Implicit Object
- The object on which a member function is called becomes the "implicit object"
- Inside the function, member variables refer to the implicit object's data
```cpp
struct Person
{
    std::string name{};
    
    void greet(const Person& other)
    {
        std::cout << name << " greets " << other.name; 
        // 'name' = implicit object's name
        // 'other.name' = explicit parameter's name
    }
};

Person alice{"Alice"};
Person bob{"Bob"};
alice.greet(bob); // alice is implicit object, bob is explicit parameter
```

### Member Function Overloading
- Member functions can be overloaded just like non-member functions
```cpp
struct Date
{
    int year{}, month{}, day{};
    
    void print() // No parameters
    {
        std::cout << year << '/' << month << '/' << day;
    }
    
    void print(std::string_view prefix) // With parameter
    {
        std::cout << prefix << year << '/' << month << '/' << day;
    }
};
```

### Best Practices
- Both structs and classes can have member functions
- Structs with member functions should avoid constructors to remain aggregates
- Classes with no data members might be better as namespaces instead