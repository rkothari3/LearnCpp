#include <iostream>
#include <string>

void changeValue(int val) {
    val = 10; // Only changes the copy 'val'
    std::cout << "Inside function: val = " << val << std::endl;
}

int main() {
    int x = 5;
    std::cout << "Before function: x = " << x << std::endl;
    changeValue(x);
    std::cout << "After function: x = " << x << std::endl;
    return 0;
}
/*
Before function: x = 5
Inside function: val = 10
After function: x = 5
*/