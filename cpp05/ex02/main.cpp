#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void testStart(const std::string name)
{
    std::cout << "-----" << name << "-----" << std::endl;
}

static void testShrubbery(void)
{
    Bureaucrat bt;
    ShrubberyCreationForm shr;

    testStart("Shrubbery");
    std::cout << bt << std::endl;
    std::cout << shr << std::endl;

    bt.signForm(shr);
    bt.executeForm(shr);
}

static void testRobotomy(void)
{
    Bureaucrat bt;
    RobotomyRequestForm rob;

    testStart("Robotomy");
    std::cout << bt << std::endl;
    std::cout << rob << std::endl;

    bt.signForm(rob);
    bt.executeForm(rob);
}

int main()
{
    testShrubbery();
    testRobotomy();
    return 0;
}
