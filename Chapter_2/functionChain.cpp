#include <iostream>
// Functions can call functions that call other functions
void name() {
    std::cout << "John";
}
void intro() {
    std::cout << "Hi, ";
    name();
}
int main() {
    intro();
    std::cout << "\nEnding program...";
}
// NOTE: the void methods don't need a return statement.