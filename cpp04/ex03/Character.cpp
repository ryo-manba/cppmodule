#include "Character.hpp"

#include <iostream>

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &type)
{
    std::cout << "Character " << type << " constructor called" << std::endl;
}

Character::Character(const Character &other)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = other;

}

Character::~Character()
{
    std::cout << "Character " << type << " destructor called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
    }
    return *this;
}
