#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

const std::string Intern::kFormNames[kNbForms] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"};

enum FormIndex
{
    kIdxShrubbery,
    kIdxRobotomy,
    kIdxPresidential
};

Intern::Intern(void) {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern&)
{
     return *this;
}

Intern::~Intern(void) {}

int Intern::checkFormName(const std::string &name) const
{
    int idx = 0;
    while ((idx < kNbForms && name != kFormNames[idx]))
    {
        idx += 1;
    }
    return idx;
}

Form *Intern::makeForm(const std::string &name, const std::string &target) const
{
    Form *fm;

    int idx = checkFormName(name);
    switch (idx)
    {
        case kIdxShrubbery:
            fm = new ShrubberyCreationForm(target);
            break;
        case kIdxPresidential:
            fm = new PresidentialPardonForm(target);
            break;
        case kIdxRobotomy:
            fm = new RobotomyRequestForm(target);
            break;
        default:
            std::cout << "Intern is not creates." << std::endl;
            return NULL;
    }
    std::cout << "Intern creates " << name << "." << std::endl;
    return fm;
}
