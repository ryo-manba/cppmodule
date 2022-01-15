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
    class NotSignedException : public std::exception
    {
    public:
        NotSignedException(const char *msg);
        const char *what() const throw();
    private:
        const char *msg;
    };

public:
    Form(void);
    Form(const Form &other);
    Form(const std::string &name, const bool &isSigned,
         const int &GradeRequiredToSign, const int &gradeRequiredToExec,
         const std::string &target);
    Form &operator=(const Form &other);
    virtual ~Form(void);

    const std::string &getName(void) const;
    const bool &getIsSigned(void) const;
    const int &getGradeRequiredToSign(void) const;
    const int &getGradeRequiredToExec(void) const;
    const std::string &getTarget(void) const;

    void beSigned(const Bureaucrat &bt);
    void execute(const Bureaucrat & executor) const;

protected:
    const static bool kDefaultIsSigned;
    const static std::string kDefaultTarget;
    void setName(const std::string &name);
    void setIsSigned(const bool &isSigned);
    void setGradeRequiredToSign(const int &grade);
    void setGradeRequiredToExec(const int &grade);
    void setTarget(const std::string &target);

private:
    const static int kHighestPossible;
    const static int kLowestPossible;
    const static std::string kDefaultName;
    const static int kDefaultGradeRequiredToSign;
    const static int kDefaultGradeRequiredToExec;
    const static char *kErrTooHighMsg;
    const static char *kErrTooLowMsg;
    const static char *kErrNotSignMsg;

    std::string name_;
    bool isSigned_;
    int gradeRequiredToSign_;
    int gradeRequiredToExec_;
    std::string target_;

    virtual void action(void) const = 0;

};

std::ostream &operator<<(std::ostream &os, const Form &a);

#endif
