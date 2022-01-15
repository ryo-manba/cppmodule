#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(void);

    void execute(Bureaucrat const & executor) const;

private:
    const static std::string kDefaultName;
    const static int kGradeRequiredToSign;
    const static int kGradeRequiredToExec;
    const static std::string kDefaultTarget;
    const static bool kDefaultIsSigned;
};
#endif
