#include <iostream>
int getValueFromUser()
{
    std::cout << "Enter a number: ";
    int input{};
    std::cin >> input;
    return input;
}
int twoSum(int addValue)
{
    int x{getValueFromUser()};
    int result{x + addValue};
    return result;
}
int main()
{
    std::cout << "Enter an add value for twoSum: ";
    int input{};
    std::cin >> input;
    std::cout << twoSum(input);
    return 0;
}