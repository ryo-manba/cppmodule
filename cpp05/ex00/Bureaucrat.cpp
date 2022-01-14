#include "Bureaucrat.hpp"

#include <iostream>

// constant
const int Bureaucrat::kHighestPossible     = 1;
const int Bureaucrat::kLowestPossible      = 150;
const int Bureaucrat::kDefaultGrade        = 42;
const std::string Bureaucrat::kDefaultName = "NONAME";
const char *Bureaucrat::kErrTooHighMsg     = "ERROR: Grade Too High";
const char *Bureaucrat::kErrTooLowMsg      = "ERROR: Grade Too Low";

// exception
Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg)
    : msg(msg)
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return msg;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg)
    : msg(msg)
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return msg;
}

Bureaucrat::Bureaucrat(void) : name_(kDefaultName), grade_(kDefaultGrade) {}
Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
    : name_(name), grade_(grade)
{
    if (grade < kHighestPossible)
    {
        throw GradeTooHighException(kErrTooHighMsg);
    }
    if (grade > kLowestPossible)
    {
        throw GradeTooLowException(kErrTooLowMsg);
    }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        name_  = other.getName();
        grade_ = other.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat(void) {}

const std::string &Bureaucrat::getName(void) const { return name_; }
const int &Bureaucrat::getGrade(void) const { return grade_; }

void Bureaucrat::incrementGrade(void)
{
    if (grade_ == kHighestPossible)
        throw GradeTooHighException(kErrTooHighMsg);
    else
        grade_ -= 1;
}

void Bureaucrat::decrementGrade(void)
{
    if (grade_ == kLowestPossible)
        throw GradeTooLowException(kErrTooLowMsg);
    else
        grade_ += 1;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &a)
{
    os << "name  : " << a.getName() << "\n"
       << "grade : " << a.getGrade();
    return os;
}
