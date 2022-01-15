#include "PresidentialPardonForm.hpp"

#include <iostream>

// Default member
const std::string PresidentialPardonForm::kDefaultName = "Presidential";
const bool PresidentialPardonForm::kDefaultIsSigned = Form::kDefaultIsSigned;
const int PresidentialPardonForm::kGradeRequiredToSign = 25;
const int PresidentialPardonForm::kGradeRequiredToExec = 5;
const std::string PresidentialPardonForm::kDefaultTarget = Form::kDefaultTarget;

PresidentialPardonForm::PresidentialPardonForm(void)
    : Form(kDefaultName,
           kDefaultIsSigned,
           kGradeRequiredToSign,
           kGradeRequiredToExec,
           kDefaultTarget)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void PresidentialPardonForm::action(void) const
{
    std::cout << "temp" << std::endl;
}
