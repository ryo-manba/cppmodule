#include "Form.hpp"

#include <iostream>

// constant
const std::string Form::kDefaultName        = "NONAME";
const bool Form::kDefaultIsSigned           = false;
const int Form::kDefaultGradeRequiredToSign = 42;
const int Form::kDefaultGradeRequiredToExec = 42;
const int Form::kHighestPossible            = 1;
const int Form::kLowestPossible             = 150;
const char *Form::kErrTooHighMsg            = "ERROR: Grade Too High";
const char *Form::kErrTooLowMsg             = "ERROR: Grade Too Low";

// exception
Form::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg)
{
}

const char *Form::GradeTooHighException::what() const throw() { return msg; }

Form::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg) {}

const char *Form::GradeTooLowException::what() const throw() { return msg; }

Form::Form(void)
    : name_(kDefaultName),
      isSigned_(kDefaultIsSigned),
      gradeRequiredToSign_(kDefaultGradeRequiredToSign),
      gradeRequiredToExec_(kDefaultGradeRequiredToExec)
{
}

Form::Form(const std::string &name, const bool &isSigned,
           const int &gradeRequiredToSign, const int &gradeRequiredToExec)
    : name_(name),
      isSigned_(isSigned),
      gradeRequiredToSign_(gradeRequiredToSign),
      gradeRequiredToExec_(gradeRequiredToExec)
{
    if (gradeRequiredToSign < kHighestPossible ||
        gradeRequiredToExec < kHighestPossible)
    {
        throw GradeTooHighException(kErrTooHighMsg);
    }
    if (gradeRequiredToSign > kLowestPossible ||
        gradeRequiredToExec > kLowestPossible)
    {
        throw GradeTooLowException(kErrTooLowMsg);
    }
}

Form::Form(const Form &other) { *this = other; }

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        name_                = other.getName();
        isSigned_            = other.getIsSigned();
        gradeRequiredToSign_ = other.getGradeRequiredToSign();
        gradeRequiredToExec_ = other.getGradeRequiredToExec();
    }
    return *this;
}

Form::~Form(void) {}

const std::string &Form::getName(void) const { return name_; }
const bool &Form::getIsSigned(void) const { return isSigned_; }
const int &Form::getGradeRequiredToSign(void) const
{
    return gradeRequiredToSign_;
}
const int &Form::getGradeRequiredToExec(void) const
{
    return gradeRequiredToExec_;
}

std::ostream &operator<<(std::ostream &os, const Form &a)
{
    os << "name                : " << a.getName() << "\n"
       << "isSigned            : " << a.getIsSigned() << "\n"
       << "gradeRequiredToSign : " << a.getGradeRequiredToSign() << "\n"
       << "gradeRequiredToExec : " << a.getGradeRequiredToExec();
    return os;
}

void Form::beSigned(const Bureaucrat &bt)
{
    if (bt.getGrade() > gradeRequiredToSign_)
        throw GradeTooLowException(kErrTooLowMsg);
    else
        isSigned_ = true;
}
