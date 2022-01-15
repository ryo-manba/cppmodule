#include "Form.hpp"

#include <iostream>

// constant
const std::string Form::kDefaultName = "NONAME";
const bool Form::kDefaultIsSigned    = false;
const int Form::kDefaultGradeToSign  = 42;
const int Form::kDefaultGradeToExec  = 42;
const int Form::kHighestPossible     = 1;
const int Form::kLowestPossible      = 150;
const char *Form::kErrTooHighMsg     = "ERROR: Grade Too High";
const char *Form::kErrTooLowMsg      = "ERROR: Grade Too Low";

// exception
Form::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg)
{
}

const char *Form::GradeTooHighException::what() const throw()
{
    return msg;
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg) {}

const char *Form::GradeTooLowException::what() const throw()
{
    return msg;
}

Form::Form(void)
    : name_(kDefaultName),
      isSigned_(kDefaultIsSigned),
      gradeToSign_(kDefaultGradeToSign),
      gradeToExec_(kDefaultGradeToExec)
{
}

Form::Form(const std::string &name, const bool &isSigned,
           const int &gradeToSign, const int &gradeToExec)
    : name_(name),
      isSigned_(isSigned),
      gradeToSign_(gradeToSign),
      gradeToExec_(gradeToExec)
{
    if (gradeToSign < kHighestPossible || gradeToExec < kHighestPossible)
    {
        throw GradeTooHighException(kErrTooHighMsg);
    }
    if (gradeToSign > kLowestPossible || gradeToExec > kLowestPossible)
    {
        throw GradeTooLowException(kErrTooLowMsg);
    }
}

Form::Form(const Form &other) { *this = other; }

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        name_        = other.getName();
        isSigned_    = other.getIsSigned();
        gradeToSign_ = other.getGradeToSign();
        gradeToExec_ = other.getGradeToExec();
    }
    return *this;
}

Form::~Form(void) {}

const std::string &Form::getName(void) const { return name_; }
const bool &Form::getIsSigned(void) const { return isSigned_; }
const int &Form::getGradeToSign(void) const { return gradeToSign_; }
const int &Form::getGradeToExec(void) const { return gradeToExec_; }

std::ostream &operator<<(std::ostream &os, const Form &a)
{
    os << "name        : " << a.getName() << "\n"
       << "isSigned    : " << a.getIsSigned() << "\n"
       << "gradeToSign : " << a.getGradeToSign() << "\n"
       << "gradeToExec : " << a.getGradeToExec();
    return os;
}

void Form::beSigned(const Bureaucrat &bt)
{
    if (bt.getGrade() > gradeToSign_)
        throw GradeTooLowException(kErrTooLowMsg);
    isSigned_ = true;
}
