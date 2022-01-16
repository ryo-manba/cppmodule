#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Required grades: sign 145, exec 137
void testShrubbery(void)
{
    Bureaucrat btOk("ok", 1);
    Bureaucrat btKo("ko", 150);
    ShrubberyCreationForm shr("shr_target");

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << shr << std::endl;

    btOk.signForm(shr);
    btOk.executeForm(shr);
    btKo.signForm(shr);
    btKo.executeForm(shr);
}

// Required grades: sign 72, exec 45
void testRobotomy(void)
{
    Bureaucrat btOk("ok", 1);
    Bureaucrat btKo("ko", 150);
    RobotomyRequestForm rob("rob_target");

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << rob << std::endl;

    srand((unsigned) time(NULL));
    btOk.signForm(rob);
    btOk.executeForm(rob);
    btKo.signForm(rob);
    btKo.executeForm(rob);
    btOk.signForm(rob);
    btOk.executeForm(rob);
}

// Required grades: sign 25, exec 5
void testPresidential(void)
{
    Bureaucrat btOk("ok", 1);
    Bureaucrat btKo("ko", 150);
    PresidentialPardonForm pre("pre_target");

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << pre << std::endl;

    btOk.signForm(pre);
    btOk.executeForm(pre);
    btKo.signForm(pre);
    btKo.executeForm(pre);
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
