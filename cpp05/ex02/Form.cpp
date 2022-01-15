#include "Form.hpp"

#include <iostream>

// Default member
const std::string Form::kDefaultName        = "NONAME";
const bool Form::kDefaultIsSigned           = false;
const int Form::kDefaultGradeRequiredToSign = 42;
const int Form::kDefaultGradeRequiredToExec = 42;
const std::string Form::kDefaultTarget      = "TARGET";

// constant
const int Form::kHighestPossible = 1;
const int Form::kLowestPossible  = 150;
const char *Form::kErrTooHighMsg = "ERROR: Grade Too High";
const char *Form::kErrTooLowMsg  = "ERROR: Grade Too Low";
const char *Form::kErrNotSignMsg = "ERROR: Not Signed";

// exception
Form::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg)
{
}
const char *Form::GradeTooHighException::what() const throw() { return msg; }

Form::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg) {}

const char *Form::GradeTooLowException::what() const throw() { return msg; }

Form::NotSignedException::NotSignedException(const char *msg) : msg(msg) {}
const char *Form::NotSignedException::what() const throw() { return msg; }

Form::Form(void)
    : name_(kDefaultName),
      isSigned_(kDefaultIsSigned),
      gradeRequiredToSign_(kDefaultGradeRequiredToSign),
      gradeRequiredToExec_(kDefaultGradeRequiredToExec),
      target_(kDefaultTarget)
{
}

Form::Form(const std::string &name, const bool &isSigned,
           const int &gradeRequiredToSign, const int &gradeRequiredToExec,
           const std::string &target)
    : name_(name),
      isSigned_(isSigned),
      gradeRequiredToSign_(gradeRequiredToSign),
      gradeRequiredToExec_(gradeRequiredToExec),
      target_(target)
{
    if (gradeRequiredToSign < kHighestPossible ||
        gradeRequiredToExec_ < kHighestPossible)
    {
        throw GradeTooHighException(kErrTooHighMsg);
    }
    if (gradeRequiredToSign > kLowestPossible ||
        gradeRequiredToExec_ > kLowestPossible)
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
        target_              = other.getTarget();
    }
    return *this;
}

Form::~Form(void) {}

// getter
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
const std::string &Form::getTarget(void) const { return target_; }

// setter
void Form::setName(const std::string &name) { name_ = name; }
void Form::setIsSigned(const bool &isSigned) { isSigned_ = isSigned; }
void Form::setGradeRequiredToSign(const int &grade)
{
    gradeRequiredToSign_ = grade;
}
void Form::setGradeRequiredToExec(const int &grade)
{
    gradeRequiredToExec_ = grade;
}
void Form::setTarget(const std::string &target) { target_ = target; }

void Form::beSigned(const Bureaucrat &bt)
{
    if (bt.getGrade() > gradeRequiredToSign_)
        throw GradeTooLowException(kErrTooLowMsg);
    else
        isSigned_ = true;
}

void Form::execute(const Bureaucrat &executor) const
{
    if (isSigned_ == false) throw NotSignedException(kErrNotSignMsg);
    if (gradeRequiredToExec_ < executor.getGrade())
        throw GradeTooLowException(kErrTooLowMsg);
    action();
}

std::ostream &operator<<(std::ostream &os, const Form &a)
{
    os << "name                : " << a.getName() << "\n"
       << "isSigned            : " << a.getIsSigned() << "\n"
       << "gradeRequiredToSign : " << a.getGradeRequiredToSign() << "\n"
       << "gradeRequiredToExec : " << a.getGradeRequiredToExec() << "\n"
       << "target              : " << a.getTarget() << std::endl;
    return os;
}
