#include "Fixed.hpp"
#include <iostream>

void Calc(Fixed const &a, Fixed const &b)
{
    std::cout << "-----Calc-----" << std::endl;
    std::cout << "[a = " << a << ",b = " << b << "]" << std::endl;
    std::cout << "a + b  : " << a + b << std::endl;
    std::cout << "a - b  : " << a - b << std::endl;
    std::cout << "a * b  : " << a * b << std::endl;
    std::cout << "a / b  : " << a / b << std::endl;
    std::cout << "min    : " << Fixed::min(a, b) << std::endl;
    std::cout << "max    : " << Fixed::max(a, b) << std::endl;
    std::cout << "a > b  : " << (a > b) << std::endl;
    std::cout << "a < b  : " << (a < b) << std::endl;
    std::cout << "a >= b : " << (a >= b) << std::endl;
    std::cout << "a <= b : " << (a <= b) << std::endl;
    std::cout << "a == b : " << (a == b) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;
}

void IncDec(Fixed a)
{
    std::cout << "-----IncDec-----" << std::endl;
    std::cout << "[a = " << a << "]" << std::endl;
    std::cout << "a      : " << a << std::endl;
    std::cout << "a++    : " << a++ << std::endl;
    std::cout << "a      : " << a << std::endl;
    std::cout << "++a    : " << ++a << std::endl;
    std::cout << "a      : " << a << std::endl;
    std::cout << "a--    : " << a-- << std::endl;
    std::cout << "a      : " << a << std::endl;
    std::cout << "--a    : " << --a << std::endl;
    std::cout << "a      : " << a << std::endl;
}

int main( void )
{
    Fixed a(1.5f);
    Fixed b(2.5f);
    Fixed const c(-3.5f);
    Fixed const d(-4.5f);

    Calc(a, b);
    Calc(c, d);
    IncDec(a);
    IncDec(c);

    return 0;
}
