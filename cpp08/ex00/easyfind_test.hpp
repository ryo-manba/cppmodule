#ifndef EASYFIND_TEST_HPP
#define EASYFIND_TEST_HPP

#include <string>

#include "easyfind.hpp"

template <typename T>
void printInfo(T& ct, const std::string& dataName)
{
    std::cout << "-----" << __func__ << "-----" <<std::endl;
    std::cout << "[" << dataName << "]" << std::endl;

    typename T::iterator itr = ct.begin();
    while (itr != ct.end())
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
}

// const
template <typename T>
void printInfo(const T& ct, const std::string& dataName)
{
    std::cout << "-----const " << __func__ << "-----" << std::endl;
    std::cout << "[" << dataName << "]" << std::endl;

    typename T::const_iterator itr = ct.begin();
    while (itr != ct.end())
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
}

template <typename T>
void testEasyFind(T& ct, const int& n)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    typename T::iterator itr = easyfind(ct, n);
    if (itr == ct.end())
        std::cout << RED << n << " is not found" << END << std::endl;
    else
        std::cout << GREEN << *itr << " is found" << END << std::endl;
}

// const
template <typename T>
void testEasyFind(const T& ct, const int& n)
{
    std::cout << "-----const " << __func__ << "-----" << std::endl;
    typename T::const_iterator itr = easyfind(ct, n);
    if (itr == ct.end())
        std::cout << RED << n << " is not found" << END << std::endl;
    else
        std::cout << GREEN << *itr << " is found" << END << std::endl;
}

#endif
