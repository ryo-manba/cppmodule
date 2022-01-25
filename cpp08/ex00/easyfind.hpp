#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& ct, const int& n)
{
    return std::find(ct.begin(), ct.end(), n);
}

template <typename T>
typename T::const_iterator easyfind(const T& ct, const int& n)
{
    return std::find(ct.begin(), ct.end(), n);
}

#endif
