#ifndef WHATEVER_TEST_HPP
#define WHATEVER_TEST_HPP

#include <iostream>
#include "whatever.hpp"

template <typename T>
void Print(const T& a, const T& b)
{
    std::cout << "a         : " << a  << "\n"
              << "address   : " << &a << "\n"
              << "b         : " << b  << "\n"
              << "address   : " << &b << std::endl;
}

template <typename T>
void testMinMax(const T& a, const T& b)
{
    std::cout << "------" << __func__ << "------" << std::endl;

    Print(a, b);
    const T& mini = ::min(a, b);
    const T& maxi = ::max(a, b);
    std::cout << "min(a, b) : " << mini << "\n"
              << "address   : " << &mini << std::endl;
    std::cout << "max(a, b) : " << maxi << "\n"
              << "address   : " << &maxi << std::endl;
}

template <typename T>
void testSwap(T& a, T& b)
{
    std::cout << "------" << __func__ << "------" << std::endl;
    Print(a, b);
    std::cout << "swap( a, b )" << std::endl;
    ::swap(a, b);
    Print(a, b);
}

#endif
