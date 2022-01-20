#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
const T& min(const T& a, const T& b)
{
    if (a < b)
        return a;
    return b;
}

template<typename T>
const T& max(const T& a, const T& b)
{
    if (a > b)
        return a;
    return b;
}

template<typename T>
void testMinMax(const T& a, const T& b)
{
    std::cout <<  __func__ << std::endl;
    std::cout << "a         : " << a << "\n"
              << "address   : " << &a << std::endl;
    std::cout << "b         : " << b << "\n"
              << "address   : " << &b << std::endl;

    const T& mini = ::min(a, b);
    const T& maxi = ::max(a, b);
    std::cout << "min(a, b) : " << mini << "\n"
              << "address   : " << &mini << std::endl;
    std::cout << "max(a, b) : " << maxi << "\n"
              << "address   : " << &maxi << std::endl;
}

template<typename T>
void testSwap(T& a, T& b)
{
    std::cout <<  __func__ << std::endl;
    std::cout << "a         : " << a << "\n"
              << "address   : " << &a << std::endl;
    std::cout << "b         : " << b << "\n"
              << "address   : " << &b << std::endl;

    std::cout << "swap( a, b )" << std::endl;
    ::swap(a, b);
    std::cout << "a         : " << a << "\n"
              << "address   : " << &a << std::endl;
    std::cout << "b         : " << b << "\n"
              << "address   : " << &b << std::endl;
}
#endif
