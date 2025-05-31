#include <iostream>

void changeReference(int& ref) {
    ref = 20; // Changes the original variable
    std::cout << "Inside function: ref = " << ref << std::endl;
}

int main() {
    int y = 15;
    std::cout << "Before function: y = " << y << std::endl;
    changeReference(y);
    std::cout << "After function: y = " << y << std::endl;
    return 0;
}

/*
Before function: y = 15
Inside function: ref = 20
After function: y = 20
*/