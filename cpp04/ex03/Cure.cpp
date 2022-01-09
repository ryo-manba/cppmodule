#include "Cure.hpp"

#include <iostream>

const std::string Cure::kDefaultType = "cure";

Cure::Cure() : AMateria(kDefaultType)
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const std::string & type) : AMateria(type)
{
    std::cout << "Cure " << type << " constructor called" << std::endl;
}

Cure::Cure(const Cure &other)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

Cure::~Cure()
{
    std::cout << "Cure " << type_ << " destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        type_ = other.getType();
    }
    return *this;
}

AMateria *Cure::clone() const
{
    return new Cure(type_);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
