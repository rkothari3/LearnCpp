#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};


// Passing structs to Functions.
// - Instead of passing each property individually, we can 
//   pass the whole struct usually by const ref. to avoid copying.
void printEmployee(const Employee& Employee)
{
    std::cout << Employee.id << '\n';
    std::cout << Employee.age << '\n';
    std::cout << Employee.wage << '\n';
}


// Returning structs from functions.
Employee getInitialEmployee()
{
    return {1, 2, 0};
}

int main()
{
    // Using the struct
    Employee frank {1, 20, 22.0};

    std::cout << frank.id << '\n';
    std::cout << frank.age << '\n';
    std::cout << frank.wage << '\n';

    std::cout << "------" << '\n';


    // Using the passing-struct function
    Employee joe { 14, 32, 24.15 };
    printEmployee(joe); // Explicity typed

    std::cout << "------" << '\n';

    // Temporary structs - use when you only need the object once.
    // - Type is deduced
    printEmployee({ 12, 3, 4.2 });


    std::cout << "------" << '\n';

    // Using the return-struct function
    Employee Baby {getInitialEmployee()};
    std::cout << Baby.id << '\n';
    std::cout << Baby.age << '\n';
    std::cout << Baby.wage << '\n';

    return 0;
}