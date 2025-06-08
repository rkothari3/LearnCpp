#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Company
{
    int numberOfEmployees {};
    Employee CEO {}; // Employee struct used as a member
    // NOTE: You could also define the struct here.
};

int main()
{
    Company myCompany{ 7, { 1, 32, 55000.0 } }; // Nested initialization
    std::cout << "CEO's wage: " << myCompany.CEO.wage << '\n';
    return 0;
}
