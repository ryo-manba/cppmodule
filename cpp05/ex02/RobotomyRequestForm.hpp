#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(void);

private:
    const static std::string kDefaultName;
    const static int kGradeRequiredToSign;
    const static int kGradeRequiredToExec;
    const static std::string kDefaultTarget;
    const static bool kDefaultIsSigned;

    const static std::string kDrillingNoises;

    void action(void) const;

};
#endif
