#include <iostream>

namespace A {
    void print() {
        std::cout << "Hello1\n";
    }
}
// Function below defined in the global namespace
void print() {
    std::cout << "Hello2\n";
}
int main() {
    // If we don't use namespace, the compiler won't be able to determine which one to use.
    // Now with namespace A, we don't have anything below, it will call the global namespace, which is the second print function.
    print();
    A::print(); // Using namespace A now, we print function 1.
    return 0;
}
