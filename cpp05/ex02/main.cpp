#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testExecute()
{
    Bureaucrat bt;
    ShrubberyCreationForm shr;

    bt.signForm(shr);
    bt.executeForm(shr);
    std::cout << bt << std::endl;
    std::cout << shr << std::endl;
}

int main()
{
    testExecute();
    return 0;
}
