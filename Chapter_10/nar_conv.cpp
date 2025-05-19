#include <iostream>

void func1(int i)
{
    std::cout << "Executed func1!\n";
}

int main()
{
    double d {5.0};

    // Narrowing using static cast
    // func1(d); // bad: implicit narrowing conversion will generate compiler warning

    func1(static_cast<int>(d)); // Using explicit casting, no warning by compilers

}

