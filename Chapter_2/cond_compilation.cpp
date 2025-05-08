#include <iostream>
#define PRINT_JOE ;
int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

#ifndef PRINT_JAKE
    std::cout << "Jake\n"; // will be compiled since it is not defined.
#endif
    return 0;

#if 0
    std::cout << "Won't compiled, because it disabled.";
    std::cout << "Switch to #if 1, to re-enable code block.";
#endif
}

