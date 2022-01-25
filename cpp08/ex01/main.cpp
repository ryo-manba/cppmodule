#include <iostream>

#include "span.hpp"

#ifndef ORIGIN
#define ORIGIN 0
#endif

void testSubject(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void tryShortestSpan(Span& sp)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    try
    {
        std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}

void tryLongestSpan(Span& sp)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    try
    {
        std::cout << "Longest  : " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testLessThanTwoElem(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    Span sp(3);
    sp.addNumber(1);
    sp.Print();

    tryShortestSpan(sp);
    tryLongestSpan(sp);
}

void testFullElem(void)
{
        std::cout << "-----" << __func__ << "-----" << std::endl;
        Span sp(1);
        sp.addNumber(1);

    try
    {
        sp.addNumber(1);
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testNormal(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    Span sp(10);
    sp.addNumber(-1);
    sp.addNumber(1);
    sp.addNumber(10);
    sp.addNumber(100);
    sp.addNumber(1000);
    sp.addNumber(10000);

    sp.Print();
    tryShortestSpan(sp);
    tryLongestSpan(sp);
}
/*
void test10000Numbers(void)
{

}
*/

int main()
{
    if (ORIGIN)
    {
        testSubject();
    }
    else
    {
        testFullElem();
        testLessThanTwoElem();
        testNormal();
    }
}
