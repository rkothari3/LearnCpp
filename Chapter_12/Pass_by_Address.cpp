#include <iostream>

void changeAddress(int* ptr) {
    *ptr = 30; // Dereference the pointer to change the value at that address
    std::cout << "Inside function: *ptr = " << *ptr << std::endl;
}

int main() {
    int z = 25;
    std::cout << "Before function: z = " << z << std::endl;
    changeAddress(&z); // Pass the address of z
    std::cout << "After function: z = " << z << std::endl;
    return 0;
}

/*
Before function: z = 25
Inside function: *ptr = 30
After function: z = 30
*/