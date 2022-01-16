#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include <string>

class Intern
{
public:
    Intern(void);
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern(void);

    Form *makeForm(const std::string &name, const std::string &target) const;

private:
    static const int kNbForms = 3;
    static const std::string kFormNames[kNbForms];

    int checkFormName(const std::string &name) const;
};

#endif
