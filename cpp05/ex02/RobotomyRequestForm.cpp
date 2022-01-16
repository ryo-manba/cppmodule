#include "RobotomyRequestForm.hpp"

#include <iostream>

// Default member
const std::string RobotomyRequestForm::kDefaultName   = "Robotomy";
const bool RobotomyRequestForm::kDefaultIsSigned      = Form::kDefaultIsSigned;
const int RobotomyRequestForm::kGradeRequiredToSign   = 72;
const int RobotomyRequestForm::kGradeRequiredToExec   = 45;
const std::string RobotomyRequestForm::kDefaultTarget = Form::kDefaultTarget;

const std::string RobotomyRequestForm::kDrillingNoises = "* DRRR! DRRR! *";

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

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        setName(other.getName());
        setIsSigned(other.getIsSigned());
        setGradeRequiredToSign(other.getGradeRequiredToSign());
        setGradeRequiredToExec(other.getGradeRequiredToExec());
        setTarget(other.getTarget());
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::action(void) const
{
    if (rand() % 2)
    {
        std::cout << kDrillingNoises << std::endl;
        std::cout << getTarget() << " has been robotomized." << std::endl;
    }
    else
    {
        std::cout << getTarget() << " robotomized has failed." << std::endl;
    }
}
