#include <iostream>
#include <string>
#include <string_view>
// std:string_view can be intialized with many different type of strings. It can be intialized with a C-style string, a std::string, or another std::string_view.
int main()
{
    // Intialize with C-style string literal
    std::string_view s1 {"Hello, World!"};
    std::cout << s1 << '\n';

    // Intialize with std::string
    std::string s{"Hello, World!"};
    std::string_view s2{s};
    std::cout << s2 << '\n';

    // Intialize with std::string_view
    std::string_view s3{s};
    std::cout << s3 << '\n';
}