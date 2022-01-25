#include "iter.hpp"

#include <iostream>
#include <string>

template<typename T>
void Print(T& a)
{
    std::cout << "------" << __func__ << "------" << std::endl;
    std::cout << a << std::endl;
}

template<typename T>
void Print(const T& a)
{
    std::cout << "------ const " << __func__ << "------" << std::endl;
    std::cout << a << std::endl;
}

template<typename T>
void toUpper(T& s)
{
    std::cout << "------" << __func__ << "------" << std::endl;
    std::cout << "Before : " << s << std::endl;
    size_t len = s.length();
    for (size_t i = 0; i < len; ++i)
    {
        if ('a' <= s[i] && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
    std::cout << "After  : " << s << std::endl;
}

template<typename T>
void toUpper(const T& s)
{
    static_cast<void>(s);
    std::cout << "------ const " << __func__ << "------" << std::endl;
    std::cout << "Constants cannot be changed." << std::endl;
}
