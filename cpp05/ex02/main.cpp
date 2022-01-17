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
    Bureaucrat bt1("bt1", 145);
    Bureaucrat bt2("bt2", 137);
    ShrubberyCreationForm shr("shr_target");

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << bt1 << std::endl;
    std::cout << bt2 << std::endl;
    std::cout << shr << std::endl;

    btOk.signForm(shr);
    btOk.executeForm(shr);
    btKo.signForm(shr);
    btKo.executeForm(shr);

    bt1.signForm(shr);
    bt1.executeForm(shr);
    bt2.signForm(shr);
    bt2.executeForm(shr);
}

// Required grades: sign 72, exec 45
void testRobotomy(void)
{
    Bureaucrat btOk("ok", 1);
    Bureaucrat btKo("ko", 150);
    Bureaucrat bt1("bt1", 72);
    Bureaucrat bt2("bt2", 45);
    RobotomyRequestForm rob("rob_target");

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << bt1 << std::endl;
    std::cout << bt2 << std::endl;
    std::cout << rob << std::endl;

    srand((unsigned) time(NULL));
    btOk.signForm(rob);
    btOk.executeForm(rob);
    btKo.signForm(rob);
    btKo.executeForm(rob);
    btOk.signForm(rob);
    btOk.executeForm(rob);

    bt1.signForm(rob);
    bt1.executeForm(rob);
    bt2.signForm(rob);
    bt2.executeForm(rob);
}

// Required grades: sign 25, exec 5
void testPresidential(void)
{
    Bureaucrat btOk("ok", 1);
    Bureaucrat btKo("ko", 150);
    Bureaucrat bt1("bt1", 25);
    Bureaucrat bt2("bt2", 5);
    PresidentialPardonForm pre("pre_target");

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << bt1 << std::endl;
    std::cout << bt2 << std::endl;
    std::cout << pre << std::endl;

    btOk.signForm(pre);
    btOk.executeForm(pre);
    btKo.signForm(pre);
    btKo.executeForm(pre);

    bt1.signForm(pre);
    bt1.executeForm(pre);
    bt2.signForm(pre);
    bt2.executeForm(pre);
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
