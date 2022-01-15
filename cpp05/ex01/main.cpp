#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void tryBeSigned(Form &f, const Bureaucrat &bt)
{
    std::cout << "-----beSigned-----" << std::endl;
    std::cout << "GradeToSign : " << f.getGradeToSign() << "\n"
              << "isSigned    : " << f.getIsSigned() << "\n"
              << "Grade       : " << bt.getGrade() << std::endl;
    try
    {
        f.beSigned(bt);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "[After]" << "\n"
              << "isSigned    : " << f.getIsSigned() << std::endl;
}

void testBeSigned()
{
    Bureaucrat bt;
    Bureaucrat high("high", 1);
    Bureaucrat low("low", 150);
    Form    f1;
    Form    f2("form", false, 1, 1);

    std::cout << "-----TEST BE SIGNED-----" << std::endl;
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
    Bureaucrat bt;
    Bureaucrat high("high", 1);
    Bureaucrat low("low", 150);
    Form    f1;
    Form    f2("form", false, 1, 1);

    std::cout << "-----TEST SIGN FORM -----" << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;

    bt.signForm(f1);
    bt.signForm(f2);
    high.signForm(f1);
    high.signForm(f2);
    low.signForm(f1);
    low.signForm(f2);
}

int main()
{
    testBeSigned();
    testSignForm();
    return 0;
}
