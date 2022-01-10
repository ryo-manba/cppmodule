#include "Cure.hpp"

#include <iostream>

const std::string Cure::kDefaultType = "cure";

Cure::Cure() : AMateria(kDefaultType) {}

Cure::Cure(const std::string &type) : AMateria(type) {}

Cure::Cure(const Cure &other) { *this = other; }

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &other)
{
    if (this != &other)
    {
        type_ = other.getType();
    }
    return *this;
}

AMateria *Cure::clone() const { return new Cure(type_); }

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
