#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// Required grades: sign 145, exec 137
void testShrubbery(Form *shr)
{
    Bureaucrat btOk("ok", 1);
    Bureaucrat btKo("ko", 150);

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << *shr << std::endl;

    btOk.signForm(*shr);
    btOk.executeForm(*shr);
    btKo.signForm(*shr);
    btKo.executeForm(*shr);
}

// Required grades: sign 72, exec 45
void testRobotomy(Form *rob)
{
    Bureaucrat btOk("ok", 1);
    Bureaucrat btKo("ko", 150);

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << *rob << std::endl;

    srand((unsigned) time(NULL));
    btOk.signForm(*rob);
    btOk.executeForm(*rob);
    btKo.signForm(*rob);
    btKo.executeForm(*rob);
    btOk.signForm(*rob);
    btOk.executeForm(*rob);
}

// Required grades: sign 25, exec 5
void testPresidential(Form *pre)
{
    Bureaucrat btOk("ok", 1);
    Bureaucrat btKo("ko", 150);

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << btOk << std::endl;
    std::cout << btKo << std::endl;
    std::cout << *pre << std::endl;

    btOk.signForm(*pre);
    btOk.executeForm(*pre);
    btKo.signForm(*pre);
    btKo.executeForm(*pre);
}

void testIntern(void)
{
    Intern someRandomIntern;
    Form* rrf;
    Form* scf;
    Form* ppf;
    Form* bad;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    testRobotomy(rrf);

    scf = someRandomIntern.makeForm("shrubbery creation", "Bender2");
    testShrubbery(scf);

    ppf = someRandomIntern.makeForm("presidential pardon", "Bender3");
    testPresidential(ppf);

    std::cout << "-----BadMakeForm-----" << std::endl;
    bad = someRandomIntern.makeForm("BAD_NAME", "bad");

    delete rrf;
    delete scf;
    delete ppf;
    delete bad;
}

// Bureaucrat : name, grade
// Form : name, isSigned, gradeRequiredToSign, gradeRequiredtoExec, target
int main()
{
    testIntern();
    return 0;
}
