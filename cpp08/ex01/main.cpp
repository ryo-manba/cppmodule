#include <iostream>
#include <list>
#include <vector>

#include "Color.hpp"
#include "span.hpp"

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
    std::cout << std::endl;
}

void tryShortestSpan(Span& sp)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    try
    {
        std::cout << "Shortest : " << GREEN << sp.shortestSpan() << END
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << END << std::endl;
    }
}

void tryLongestSpan(Span& sp)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    try
    {
        std::cout << "Longest  : " << GREEN << sp.longestSpan() << END
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << END << std::endl;
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
    std::cout << std::endl;
}

void testFullElem(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    Span sp(1);
    sp.addNumber(1);

    try
    {
        sp.addNumber(1);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << END << std::endl;
    }
    std::cout << std::endl;
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
    std::cout << std::endl;
}

void testIterAddNumber(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    Span sp1(10);
    Span sp2(10);
    std::vector<int> vec;
    std::list<int> lst;
    for (size_t i = 0; i < 10; ++i)
    {
        vec.push_back(i);
        lst.push_back(i);
    }
    sp1.addNumber(vec.begin(), vec.begin() + 5);
    std::cout << "[sp1]" << std::endl;
    sp1.Print();

    sp2.addNumber(lst.begin(), lst.end());
    std::cout << "[sp2]" << std::endl;
    sp2.Print();
    try
    {
        sp1.addNumber(vec.begin(), vec.end());
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << END << std::endl;
    }
    std::cout << std::endl;
}

void test10000Numbers(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    Span sp(10000);

    for (size_t i = 0; i < 10000; ++i)
    {
        sp.addNumber(i);
    }
    tryShortestSpan(sp);
    tryLongestSpan(sp);
    std::cout << std::endl;
}

int main()
{
    testSubject();
    testFullElem();
    testLessThanTwoElem();
    testNormal();
    testIterAddNumber();
    test10000Numbers();
}
