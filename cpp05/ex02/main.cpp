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

// Required grades: sign 145, exec 137
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

// Required grades: sign 72, exec 45
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

// Required grades: sign 25, exec 5
static void testPresidential(void)
{
    Bureaucrat bt("bt", 1);
    PresidentialPardonForm pre;

    testStart("Presidential");
    std::cout << bt << std::endl;
    std::cout << pre << std::endl;

    bt.signForm(pre);
    bt.executeForm(pre);
}

// Bureaucrat : name, grade
// Form : name, isSigned, gradeRequiredToSign, gradeRequiredtoExec, target
int main()
{
    testShrubbery();
    testRobotomy();
    testPresidential();
    return 0;
}
