#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat
{
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
    Bureaucrat(void);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat(const std::string &name, const int &grade);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat(void);

    const std::string &getName(void) const;
    const int &getGrade(void) const;

    void incrementGrade(void);
    void decrementGrade(void);
    void signForm(Form &fm);
    void executeForm(Form const & form);

private:
    const static int kHighestPossible;
    const static int kLowestPossible;
    const static int kDefaultGrade;
    const static std::string kDefaultName;
    const static char *kErrTooHighMsg;
    const static char *kErrTooLowMsg;

    std::string name_;
    int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &a);

#endif
