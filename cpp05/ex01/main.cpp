#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void tryBeSigned(Form &fm, const Bureaucrat &bt)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << "GradeRequiredToSign : " << fm.getGradeRequiredToSign() << "\n"
              << "isSigned            : " << fm.getIsSigned() << "\n"
              << "Grade               : " << bt.getGrade() << std::endl;
    try
    {
        fm.beSigned(bt);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "[After]"
              << "\n"
              << "isSigned            : " << fm.getIsSigned() << std::endl;
}

void testBeSigned()
{
    Bureaucrat bt("bt", 42);
    Bureaucrat high("high", 1);
    Bureaucrat low("low", 150);
    Form f1;
    Form f2("form", false, 1, 1);

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    tryBeSigned(f1, bt);
    tryBeSigned(f1, high);
    tryBeSigned(f1, low);
    tryBeSigned(f2, bt);
    tryBeSigned(f2, high);
    tryBeSigned(f2, low);
}

void testSignForm()
{
    Bureaucrat bt("bt", 42);
    Bureaucrat high("high", 1);
    Bureaucrat low("low", 150);
    Form f1("f1", false, 42, 42);
    Form f2("f2", false, 1, 1);

    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << bt << std::endl;
    std::cout << high << std::endl;
    std::cout << low << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    bt.signForm(f1);
    bt.signForm(f2);
    high.signForm(f1);
    high.signForm(f2);
    low.signForm(f1);
    low.signForm(f2);
}

void testCreateForm(const std::string &name, const bool &isSigned,
         const int &gradeRequiredToSign, const int &gradeRequiredToExec)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << "name                : " << name << "\n"
              << "isSigned            : " << isSigned << "\n"
              << "gradeRequiredToSign : " << gradeRequiredToSign << "\n"
              << "gradeRequiredToExec : " << gradeRequiredToExec << std::endl;
    try
    {
        Form(name, isSigned, gradeRequiredToSign, gradeRequiredToExec);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    testBeSigned();
    testSignForm();
    testCreateForm("Error", false, 151, 42);
    testCreateForm("Error", false, 42, 151);
    testCreateForm("Error", false, 0, 42);
    testCreateForm("Error", false, 42, 0);
    return 0;
}
