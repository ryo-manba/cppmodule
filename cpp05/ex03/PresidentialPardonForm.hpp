#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <string>

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm&);
    ~PresidentialPardonForm(void);

private:
    const static std::string kDefaultName;
    const static int kGradeRequiredToSign;
    const static int kGradeRequiredToExec;
    const static std::string kDefaultTarget;
    const static bool kDefaultIsSigned;

    void action(void) const;
};
#endif
