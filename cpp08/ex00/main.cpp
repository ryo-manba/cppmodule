#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

#include "Color.hpp"
#include "easyfind.hpp"
#include "easyfind_test.hpp"

void testVariable(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::vector<int> vec;
    std::list<int> lst;
    std::deque<int> deq;
    std::set<int> st;

    for (size_t i = 0; i < 10; ++i)
    {
        vec.push_back(i);
        lst.push_back(i);
        deq.push_back(i);
        st.insert(i);
    }

    printInfo(vec, "vector");
    testEasyFind(vec, 5);
    testEasyFind(vec, 42);
    testEasyFind(vec, -1);
    std::cout << std::endl;

    printInfo(lst, "list");
    testEasyFind(lst, 5);
    testEasyFind(lst, 42);
    testEasyFind(lst, -1);
    std::cout << std::endl;

    printInfo(deq, "deque");
    testEasyFind(deq, 5);
    testEasyFind(deq, 42);
    testEasyFind(deq, -1);
    std::cout << std::endl;

    printInfo(st, "set");
    testEasyFind(st, 5);
    testEasyFind(st, 42);
    testEasyFind(st, -1);
    std::cout << std::endl;
}

void testConstant(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    const int values[] = {1, 2, 3, 4, 5, 6, 7};
    const std::vector<int> vec(values, values + 7);
    const std::list<int> lst(values, values + 7);
    const std::deque<int> deq(values, values + 7);
    const std::set<int> st(values, values + 7);

    printInfo(vec, "vector");
    testEasyFind(vec, 5);
    testEasyFind(vec, 42);
    testEasyFind(vec, -1);
    std::cout << std::endl;

    printInfo(lst, "list");
    testEasyFind(lst, 5);
    testEasyFind(lst, 42);
    testEasyFind(lst, -1);
    std::cout << std::endl;

    printInfo(deq, "deque");
    testEasyFind(deq, 5);
    testEasyFind(deq, 42);
    testEasyFind(deq, -1);
    std::cout << std::endl;

    printInfo(st, "set");
    testEasyFind(st, 5);
    testEasyFind(st, 42);
    testEasyFind(st, -1);
    std::cout << std::endl;
}

int main(void)
{
    testVariable();
    testConstant();
}
