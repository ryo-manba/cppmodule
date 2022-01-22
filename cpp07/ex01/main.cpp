#include "iter.hpp"
#include "iter_test.hpp"
#include <iostream>

int main(void)
{
    std::string lowers[] = {"hello", "world", "tokyo"};
    std::string uppers[] = {"HELLO", "WORLD", "TOKYO"};
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    ::iter(lowers, 1, putUpper);
    ::iter(uppers, 3, putLower);
    ::iter(array, 5, print);
    return 0;
}
