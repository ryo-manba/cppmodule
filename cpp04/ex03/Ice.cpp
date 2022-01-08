#include "Ice.hpp"

const std::string kDefaultType = "ice";

Ice::Ice() : AMateria(kDefaultType)
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other)
{
    *this = other;
}
Ice::~Ice()
{
}
Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
    }
    return *this;
}
