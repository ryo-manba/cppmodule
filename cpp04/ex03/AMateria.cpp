#include "AMateria.hpp"

#include <iostream>

const std::string AMateria::kDefaultType = "NOTYPE";

AMateria::AMateria() : type_(kDefaultType)
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type_(type)
{
    std::cout << "AMateria " << type << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = other;
}

AMateria::~AMateria()
{
    std::cout << "AMateria " << type_ << " destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        this->type_ = other.getType();
    }
    return *this;
}

std::string const &AMateria::getType() const
{
    return type_;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria use" << target.getName() << std::endl;
}
