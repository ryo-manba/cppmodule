#include <iostream>

#include "whatever.hpp"
#include "whatever_test.hpp"

#ifndef ORIGIN
#define ORIGIN 0
#endif

void testSubject(void)
{
    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void test(void)
{
    int ia         = 42;
    int ib         = 42;
    long la        = 42;
    long lb        = 42;
    double da      = 42.0;
    double db      = 42.0;
    float fa       = 42.0f;
    float fb       = 42.0f;
    std::string sa = "42";
    std::string sb = "42";

    // If commented out, both sides will have the same value.
    //
    ia *= -1;
    la *= -1;
    da *= -1;
    fa *= -1;
    sa = "1";
    //

    testMinMax(ia, ib);
    testMinMax(la, lb);
    testMinMax(da, db);
    testMinMax(fa, fb);
    testMinMax(ia, ib);
    testMinMax(sa, sb);

    testSwap(ia, ib);
    testSwap(la, lb);
    testSwap(da, db);
    testSwap(fa, fb);
    testSwap(ia, ib);
    testSwap(sa, sb);
}

int main(void)
{
    if (ORIGIN)
        testSubject();
    else
        test();
    return 0;
}
