#include "iter.hpp"

#include <iostream>
#include <string>

template<typename T>
void print(const T& a)
{
    std::cout << a << std::endl;
}

template<typename T>
void putLower(const T& s)
{
    std::string ans;
    {
        size_t  len = s.length();
        for (size_t i = 0; i < len; ++i)
        {
            if ('A' <= s[i] && s[i] <= 'Z')
                ans += (s[i] + 32);
            else
                ans += s[i];
        }
    std::cout << ans << std::endl;
    }
}

template<typename T>
void putUpper(const T& s)
{
    std::string ans = "";
    size_t  len = s.length();
    for (size_t i = 0; i < len; ++i)
    {
        if ('a' <= s[i] && s[i] <= 'z')
            ans += (s[i] - 32);
        else
            ans += s[i];
    }
    std::cout << ans << std::endl;
}
