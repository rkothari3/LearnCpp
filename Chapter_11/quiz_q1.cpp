/*
1.a) Output of program?
*/
#include <iostream>

void print(int x)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    short s { 5 };
    print(s);

    return 0;
}
/*
The output is int 5. Converting a short to an int is a numeric promotion, whereas converting a short to a double is a numeric conversion. The compiler will favor the option that is a numeric promotion over the option that is a numeric conversion.
*/

/*
1.b) Why won't the code compile?
*/
#include <iostream>

void print()
{
    std::cout << "void\n";
}

void print(int x=0)
{
    std::cout << "int " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5.0f);
    print(); // Compiler can't tell whether to use the print with default args or print with no args. (Ambigous Invocation)

    return 0;
}

/*
1.c) Why won't the code compile?
*/
#include <iostream>

void print(long x)
{
    std::cout << "long " << x << '\n';
}

void print(double x)
{
    std::cout << "double " << x << '\n';
}

int main()
{
    print(5);
    // Both are widening conversion so compiler can't determine which one to use.
    return 0;
}
