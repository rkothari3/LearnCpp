#include <iostream>
#include <string>

std::string getName(int num)
{
    std::cout << "Enter the name of person #" << num << ": ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    return name;
}

int getAge(std::string name)
{
    std::cout << "Enter the age of " << name << ": ";
    int age{};
    std::cin >> age;
    return age;
}

// printOlder function
// string params use string_view
// std::string can be implicitly converted to string_view
// string_view offers a read-only access
void printOlder(std::string_view name1, int age1, std::string_view name2, int age2)
{
    if (age1 > age2)
        std::cout << name1 << " (age " << age1 <<") is older than " << name2 << " (age " << age2 <<").\n";
    else
        std::cout << name2 << " (age " << age2 <<") is older than " << name1 << " (age " << age1 <<").\n";
}

int main()
{
    // NOTE: DONT DO ALL THIS BC NOT THE MOST OPTIMAL WAY
    // // Name 1
    // std::cout << "Enter the name of person #1: ";
    // std::string name1;
    // std::getline(std::cin >> std::ws, name1);
    // std::cout << name1 << '\n';

    // // Age 1
    // std::cout << "Enter the age of " << name1 << ": ";
    // int age1;
    // std::cin >> age1;
    // std::cout << age1 << '\n';

    // // Name 2
    // std::cout << "Enter the name of person #2: ";
    // std::string name2;
    // std::getline(std::cin >> std::ws, name2);
    // std::cout << name2 << '\n';

    // // Age 2
    // std::cout << "Enter the age of " << name2 << ": ";
    // int age2;
    // std::cin >> age2;
    // std::cout << age2 << '\n';


    // These variables cannot be constexpr because those require a constant expression intializer, getAge and getName are not constant intializers.

    const std::string name1{ getName(1) };
    const int age1{ getAge(name1) };

    const std::string name2{ getName(2) };
    const int age2{ getAge(name2) };

    printOlder(name1, age1, name2, age2);

    return 0;
}
