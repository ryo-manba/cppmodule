#include <iostream>

#include "Bureaucrat.hpp"

void testIncrement(Bureaucrat *a)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << "Before : " << a->getGrade() << std::endl;
    try
    {
        a->incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "After  : " << a->getGrade() << std::endl;
}

void testDecrement(Bureaucrat *a)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << "Before : " << a->getGrade() << std::endl;
    try
    {
        a->decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "After  : " << a->getGrade() << std::endl;
}

void testCreate(const std::string &name, const int &grade)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << "name  : " << name
              << " grade : " << grade << std::endl;
    try
    {
        Bureaucrat(name, grade);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    Bureaucrat a;
    Bureaucrat high("high", 1);
    Bureaucrat low("low", 150);

    std::cout << a << std::endl;
    std::cout << high << std::endl;
    std::cout << low << std::endl;

    testIncrement(&a);
    testDecrement(&a);

    // Out of range.
    testIncrement(&high);
    testDecrement(&low);

    testCreate("high", 0);
    testCreate("low", 151);

    return 0;
}
