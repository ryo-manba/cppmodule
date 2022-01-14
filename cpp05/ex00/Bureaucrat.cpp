#include "Bureaucrat.hpp"

#include <iostream>

const int Bureaucrat::kHighestPossible     = 1;
const int Bureaucrat::kLowestPossible      = 150;
const int Bureaucrat::kDefaultGrade        = 42;
const std::string Bureaucrat::kDefaultName = "NONAME";
const char *Bureaucrat::kErrTooHighMsg     = "ERROR: Grade Too High";
const char *Bureaucrat::kErrTooLowMsg      = "ERROR: Grade Too Low";

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

Bureaucrat::Bureaucrat() : name_(kDefaultName), grade_(kDefaultGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
    : name_(name), grade_(grade)
{
    if (grade < kHighestPossible)
    {
        throw GradeTooLowException(kErrTooLowMsg);
    }
    if (grade > kLowestPossible)
    {
        throw GradeTooHighException(kErrTooHighMsg);
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

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return name_; }

const int &Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade()
{
    if (grade_ == kHighestPossible)
        throw GradeTooHighException(kErrTooHighMsg);
    else
        grade_ -= 1;
}

void Bureaucrat::decrementGrade()
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
