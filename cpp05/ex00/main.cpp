#include <iostream>

#include "Bureaucrat.hpp"

static void tryIncrement(Bureaucrat *a)
{
    std::cout << "-----Increment-----" << std::endl;
    std::cout << "Before :" << a->getGrade() << std::endl;
    try
    {
        a->incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "After  :" << a->getGrade() << std::endl;
}

static void tryDecrement(Bureaucrat *a)
{
    std::cout << "-----Decrement-----" << std::endl;
    std::cout << "Before :" << a->getGrade() << std::endl;
    try
    {
        a->decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "After  :" << a->getGrade() << std::endl;
}

int main()
{
    Bureaucrat a;
    Bureaucrat high("high", 1);
    Bureaucrat low("low", 150);

    std::cout << a << std::endl;
    std::cout << high << std::endl;
    std::cout << low << std::endl;

    tryIncrement(&a);
    tryDecrement(&a);

    // Out of range.
    tryIncrement(&high);
    tryDecrement(&low);
    return 0;
}
