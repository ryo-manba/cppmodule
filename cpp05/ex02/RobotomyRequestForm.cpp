#include "RobotomyRequestForm.hpp"

// Default member
const std::string RobotomyRequestForm::kDefaultName = "Robotomy";
const bool RobotomyRequestForm::kDefaultIsSigned = Form::kDefaultIsSigned;
const int RobotomyRequestForm::kGradeRequiredToSign = 72;
const int RobotomyRequestForm::kGradeRequiredToExec = 45;
const std::string RobotomyRequestForm::kDefaultTarget = Form::kDefaultTarget;

RobotomyRequestForm::RobotomyRequestForm(void)
    : Form(kDefaultName,
           kDefaultIsSigned,
           kGradeRequiredToSign,
           kGradeRequiredToExec,
           kDefaultTarget)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}
