#include "Ice.hpp"

#include <iostream>

const std::string Ice::kDefaultType = "ice";

Ice::Ice() : AMateria(kDefaultType)
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const std::string & type) : AMateria(type)
{
    std::cout << "Ice " << type << " constructor called" << std::endl;
}

Ice::Ice(const Ice &other)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

Ice::~Ice()
{
    std::cout << "Ice " << type_ << " destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        type_ = other.getType();
    }
    return *this;
}

AMateria *Ice::clone() const
{
    return new Ice(type_);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
