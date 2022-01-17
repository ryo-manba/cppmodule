#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException(const char *msg);
        const char *what() const throw();

    private:
        const char *msg;
    };
    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException(const char *msg);
        const char *what() const throw();

    private:
        const char *msg;
    };

public:
    Form(void);
    Form(const Form &other);
    Form(const std::string &name, const bool &isSigned,
         const int &gradeRequiredToSign, const int &gradeRequiredToExec);
    Form &operator=(const Form &other);
    ~Form(void);

    const std::string &getName(void) const;
    const bool &getIsSigned(void) const;
    const int &getGradeRequiredToSign(void) const;
    const int &getGradeRequiredToExec(void) const;

    void beSigned(const Bureaucrat &bt);

private:
    const static int kHighestPossible;
    const static int kLowestPossible;
    const static std::string kDefaultName;
    const static bool kDefaultIsSigned;
    const static int kDefaultGradeRequiredToSign;
    const static int kDefaultGradeRequiredToExec;
    const static char *kErrTooHighMsg;
    const static char *kErrTooLowMsg;

    std::string name_;
    bool isSigned_;
    int gradeRequiredToSign_;
    int gradeRequiredToExec_;
};

std::ostream &operator<<(std::ostream &os, const Form &a);

#endif
