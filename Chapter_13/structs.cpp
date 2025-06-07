#include <iostream>

struct Employee {
    int id {};
    int age {};
    double wage { 50000.0 };
};

// Overload << for readable output
std::ostream& operator<<(std::ostream& out, const Employee& e) {
    out << "ID: " << e.id << ", Age: " << e.age << ", Wage: " << e.wage;
    return out;
}

int main() {
    // List initialization
    Employee joe { 1, 30 }; // id = 1, age = 30, wage = 50000.0 (default)
    std::cout << joe << '\n'; // Prints: ID: 1, Age: 30, Wage: 50000

    // Designated initializers (C++20)
    Employee alice { .id = 2, .age = 25 }; // id = 2, age = 25, wage = 50000.0
    std::cout << alice << '\n'; // Prints: ID: 2, Age: 25, Wage: 50000

    // Assignment with initializer list
    joe = { joe.id, 31, 55000.0 }; // Update age and wage
    std::cout << joe << '\n'; // Prints: ID: 1, Age: 31, Wage: 55000

    // Copy initialization
    Employee bob = joe; // Copy joe's values
    std::cout << bob << '\n'; // Prints: ID: 1, Age: 31, Wage: 55000

    return 0;
}