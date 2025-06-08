# Quick review

A **program-defined type** (also called a user-defined type) is a custom type that we can create for use in our own programs. The enumerated types and class types (including structs, classes and unions) allow for creation of program-defined types. Program-defined types must be defined before they can be used. The definition of a program-defined type is called a **type definition**. Type definitions are exempt from the one-definition rule.

An **enumeration** (also called an enumerated type or an enum) is a compound data type where every possible value is defined as a symbolic constant (called an enumerator). Enumerations are distinct types, meaning the compiler can differentiate them from other types (unlike type aliases).

**Unscoped enumerations** are named such because they put their enumerator names into the same scope as the enumeration definition itself (as opposed to creating a new scope region like a namespace does). Unscoped enumerations also provide a named scope region for their enumerators. Unscoped enumerations will implicitly convert to integral values.

**Scoped enumerations** work similarly to unscoped enumerations but won’t implicitly convert to integers, and the enumerators are only placed into the scope region of the enumeration (not into the scope region where the enumeration is defined).

A **struct** (short for structure) is a program-defined data type that allows us to bundle multiple variables together into a single type. The variables that are part of the struct (or class) are called **data members** (or member variables). To access a specific member variable, we use the member selection operator (`.`) in between the struct variable name and the member name (for normal structs and references to structs), or the member selection from pointer operator (`->`) (for pointers to structs).

In general programming, an **aggregate data type** (also called an aggregate) is any type that can contain multiple data members. In C++, arrays and structs with only data members are aggregates.

Aggregates use a form of initialization called **aggregate initialization**, which allows us to directly initialize the members of aggregates. To do this, we provide an initializer list as an initializer, which is just a list of comma-separated values. Aggregate initialization does a memberwise initialization, which means each member in the struct is initialized in the order of declaration.

```cpp
struct Employee {
    int id;
    double wage;
    int age;
};

Employee frank { 1, 25.50, 32 }; // frank.id = 1, frank.wage = 25.50, frank.age = 32

// We can provide fewer initializers than members
Employee joe { 2, 22.25 }; // joe.id = 2, joe.wage = 22.25, joe.age = 0 (default initialization)

// We can skip initializing specific members using empty braces
struct Point3D {
    double x;
    double y;
    double z;
};

Point3D origin { 0.0, 0.0, 0.0 }; // All zeros
Point3D pointXZ { 5.0, {}, 3.0 }; // x = 5.0, y = 0.0 (value-initialized), z = 3.0
```

In C++20, **Designated initializers** allow you to explicitly define which initialization values map to which members. The members must be initialized in the order in which they are declared in the struct, otherwise an error will result.

```cpp
struct Employee {
    int id;
    double wage;
    int age;
};

// Using designated initializers
Employee frank { .id = 1, .wage = 25.50, .age = 32 }; // OK
// Employee joe { .wage = 22.25, .id = 2, .age = 31 }; // Error: members must be in declaration order
```

When we define a struct (or class) type, we can provide a default initialization value for each member as part of the type definition. This process is called **non-static member initialization**, and the initialization value is called a **default member initializer**.

```cpp
struct Rectangle {
    double length { 1.0 }; // default member initializer
    double width { 1.0 };  // default member initializer
};

Rectangle r1; // length = 1.0, width = 1.0 (default values)
Rectangle r2 { 2.5 }; // length = 2.5, width = 1.0 (default used for width)
Rectangle r3 { 3.0, 4.0 }; // length = 3.0, width = 4.0 (overrides both defaults)
```

For performance reasons, the compiler will sometimes add gaps into structures (this is called **padding**), so the size of a structure may be larger than the sum of the size of its members.

A **class template** is a template definition for instantiating class types (structs, classes, or unions). **Class template argument deduction (CTAD)** is a C++17 feature that allows the compiler to deduce the template type arguments from an initializer.
