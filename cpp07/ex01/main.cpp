#include <iostream>

#include "iter.hpp"
#include "iter_test.hpp"

void testVariable(void)
{
    std::cout << "------" << __func__ << "------" << std::endl;
    std::string lowers[] = {"hello", "world", "tokyo"};
    int array[]          = {1, 2, 3, 4, 5};

    ::iter(lowers, 2, toUpper);
    ::iter(array, 3, Print);
}

void testConst(void)
{
    std::cout << "------" << __func__ << "------" << std::endl;
    const std::string lowers[] = {"hello", "world", "tokyo"};
    const int array[]          = {1, 2, 3, 4, 5};

    ::iter(lowers, 2, toUpper);
    ::iter(array, 3, Print);
}

int main(void)
{
    testVariable();
    testConst();
    return 0;
}
