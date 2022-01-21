#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm(void);

private:
    const static std::string kDefaultName;
    const static int kGradeRequiredToSign;
    const static int kGradeRequiredToExec;
    const static std::string kDefaultTarget;
    const static bool kDefaultIsSigned;

    const static char *kAsciiTree;

    void action(void) const;
};

#endif
