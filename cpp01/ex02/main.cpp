#include <iostream>

#define BRAIN "HI THIS IS BRAIN"

int main(void)
{
    std::string base = BRAIN;

    std::string *stringPTR = &base;
    std::string &stringREF = base;

    std::cout << "[Address]" << std::endl;
    std::cout << "base      : [" << &base << "]" << std::endl
              << "stringPTR : [" << stringPTR << "]" << std::endl
              << "stringREF : [" << &stringREF << "]" << std::endl << std::endl;

    std::cout << "[String]" << std::endl;
    std::cout << "base      : [" << base << "]" << std::endl
              << "stringPTR : [" << *stringPTR << "]" << std::endl
              << "stringREF : [" << stringREF << "]" << std::endl;

    return (0);
}
