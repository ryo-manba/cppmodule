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
    Form(const std::string &name, const bool &isSigned, const int &gradeToSign,
         const int &gradeToExec);
    Form &operator=(const Form &other);
    ~Form(void);

    const std::string &getName(void) const;
    const bool &getIsSigned(void) const;
    const int &getGradeToSign(void) const;
    const int &getGradeToExec(void) const;

    void beSigned(const Bureaucrat &bt);

private:
    const static int kHighestPossible;
    const static int kLowestPossible;
    const static std::string kDefaultName;
    const static bool kDefaultIsSigned;
    const static int kDefaultGradeToSign;
    const static int kDefaultGradeToExec;
    const static char *kErrTooHighMsg;
    const static char *kErrTooLowMsg;

    std::string name_;
    bool isSigned_;
    int gradeToSign_;
    int gradeToExec_;
};

std::ostream &operator<<(std::ostream &os, const Form &a);

#endif
