/*
Named vs. Literal constants
- Literal constants make the code harder to read because the meaning of the number is unclear.
- Named constants only need to update the value in one place if it changes.
*/

#include <iostream>
int main()
{
    const double PI = 3.14; // Named constant
    int radius = 5;
    double area = PI * radius * radius;
    return 0;
}