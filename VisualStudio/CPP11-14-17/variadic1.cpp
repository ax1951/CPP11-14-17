#include "variadic1.h"
#include <iostream>
#include <string>

// definition for 0 parameters
void show_list() {}

template<typename T>
void show_list(T value)
{
    std::cout << value << '\n';
}

// definition for 2 or more parameters
template<typename T, typename... Args>
void show_list(const T& value, const Args&... args)
{
    std::cout << value << ", ";
    show_list(args...);
}

int testVariadic() {
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list(n, x);
    std::cout << std::endl;
    show_list(x * x, '!', 7, mr);
    return 0;
}

