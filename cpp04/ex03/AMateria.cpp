#include "AMateria.hpp"

#include <iostream>

const std::string AMateria::kDefaultType = "NOTYPE";

AMateria::AMateria() : type_(kDefaultType) {}

AMateria::AMateria(std::string const &type) : type_(type) {}

AMateria::AMateria(const AMateria &other) { *this = other; }

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        type_ = other.getType();
    }
    return *this;
}

std::string const &AMateria::getType() const { return type_; }

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria use" << target.getName() << std::endl;
}
