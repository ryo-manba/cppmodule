#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

// Default member
const std::string ShrubberyCreationForm::kDefaultName = "Shrubbery";
const bool ShrubberyCreationForm::kDefaultIsSigned    = Form::kDefaultIsSigned;
const int ShrubberyCreationForm::kGradeRequiredToSign = 145;
const int ShrubberyCreationForm::kGradeRequiredToExec = 137;
const std::string ShrubberyCreationForm::kDefaultTarget = Form::kDefaultTarget;

const char* ShrubberyCreationForm::kAsciiTree = ""
"    _\\/_\n"
"     /\\\n"
"     /\\\n"
"    /  \\\n"
"    /~~\\o\n"
"   /o   \\\n"
"  /~~*~~~\\\n"
" o/    o \\\n"
" /~~~~~~~~\\\n"
"/__*_______\\\n"
"     ||\n"
"   \\====/\n"
"    \\__/\n";

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : Form(kDefaultName,
           kDefaultIsSigned,
           kGradeRequiredToSign,
           kGradeRequiredToExec,
           kDefaultTarget)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        setName(other.getName());
        setIsSigned(other.getIsSigned());
        setGradeRequiredToSign(other.getGradeRequiredToSign());
        setGradeRequiredToExec(other.getGradeRequiredToExec());
        setTarget(other.getTarget());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::action(void) const
{
    std::ofstream file;
    std::string const filename = getTarget() + "_shrubbery";
    try
    {
        file.open(filename, std::ios::out);
        file << kAsciiTree << std::endl;
        file.close();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
