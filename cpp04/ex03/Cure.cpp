#include "Cure.hpp"

#include <iostream>

const std::string kDefaultType = "cure";

Cure::Cure() : AMateria(kDefaultType)
{
    std::cout << "Cure default constructor called" << std::endl;
}
Cure::Cure(const Cure &other)
{
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
    }
    return *this;
}
