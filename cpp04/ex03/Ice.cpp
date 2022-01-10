#include "Ice.hpp"

#include <iostream>

const std::string Ice::kDefaultType = "ice";

Ice::Ice() : AMateria(kDefaultType) {}

Ice::Ice(const std::string &type) : AMateria(type) {}

Ice::Ice(const Ice &other) { *this = other; }

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
    {
        type_ = other.getType();
    }
    return *this;
}

AMateria *Ice::clone() const { return new Ice(type_); }

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}
