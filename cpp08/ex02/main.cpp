#include <iostream>
#include <list>
#include <stack>
#include "mutantstack.hpp"

#ifdef LIST
# define push push_back
# define pop pop_back
# define MutantStack std::list
#endif

int testSubject(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    #ifndef LIST
        std::cout << mstack.top() << std::endl;
    #else
        std::cout << "std::list does not have a top()" << std::endl;
    #endif
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    #ifndef LIST
        std::stack<int> s(mstack);
    #else
        std::list<int> s(mstack);
    #endif
    return 0;
}

void testIterator(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    MutantStack<int>::iterator it              = mstack.begin();
    MutantStack<int>::iterator ite             = mstack.end();
    MutantStack<int>::reverse_iterator rev_it  = mstack.rbegin();
    MutantStack<int>::reverse_iterator rev_ite = mstack.rend();

    std::cout << "[Iterator]" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "[Reverse Iterator]" << std::endl;
    while (rev_it != rev_ite)
    {
        std::cout << *rev_it << std::endl;
        ++rev_it;
    }
}

void testConstIterator(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    const MutantStack<int> constMstack(mstack);
    MutantStack<int>::const_iterator it              = constMstack.begin();
    MutantStack<int>::const_iterator ite             = constMstack.end();
    MutantStack<int>::const_reverse_iterator rev_it  = constMstack.rbegin();
    MutantStack<int>::const_reverse_iterator rev_ite = constMstack.rend();

    std::cout << "[Const Iterator]" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "[Const Reverse Iterator]" << std::endl;
    while (rev_it != rev_ite)
    {
        std::cout << *rev_it << std::endl;
        ++rev_it;
    }
}

int main(void)
{
    #ifdef LIST
        std::cout << "[std::list]" << std::endl;
    #else
        std::cout << "[MutantStack]" << std::endl;
    #endif
    testSubject();
    testIterator();
    testConstIterator();
}
