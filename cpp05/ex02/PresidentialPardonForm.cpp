#include "PresidentialPardonForm.hpp"

#include <iostream>

// Default member
const std::string PresidentialPardonForm::kDefaultName   = "Presidential";
const bool PresidentialPardonForm::kDefaultIsSigned      = Form::kDefaultIsSigned;
const int PresidentialPardonForm::kGradeRequiredToSign   = 25;
const int PresidentialPardonForm::kGradeRequiredToExec   = 5;
const std::string PresidentialPardonForm::kDefaultTarget = Form::kDefaultTarget;

PresidentialPardonForm::PresidentialPardonForm(void)
    : Form(kDefaultName,
           kDefaultIsSigned,
           kGradeRequiredToSign,
           kGradeRequiredToExec,
           kDefaultTarget)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form(kDefaultName,
           kDefaultIsSigned,
           kGradeRequiredToSign,
           kGradeRequiredToExec,
           target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : Form(other)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &)
{
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::action(void) const
{
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox."
              << std::endl;
}
