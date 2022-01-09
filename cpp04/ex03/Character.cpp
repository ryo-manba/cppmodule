#include "Character.hpp"

#include <iostream>

const std::string Character::kDefaultName = "NONAME";

Character::Character() : name_(kDefaultName)
{
    std::cout << "Character default constructor called" << std::endl;
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        materia_[i] = NULL;
    }
}

Character::Character(std::string const &name) : name_(name)
{
    std::cout << "Character " << name_ << " constructor called" << std::endl;
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        materia_[i] = NULL;
    }
}

Character::Character(const Character &other)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = other;
}

Character::~Character()
{
    std::cout << "Character " << name_ << " destructor called" << std::endl;
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        if (materia_[i])
        {
            delete materia_[i];
        }
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        
    }
    return *this;
}

std::string const &Character::getName() const
{
    return name_;
}

void Character::equip(AMateria *m)
{
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        if (materia_[i] == NULL)
        {
            materia_[i] = m;
            return ;
        }
    }
}

bool Character::isValidIndex(int idx) const
{
    return 0 <= idx && idx < static_cast<int>(kMaxMateria);
}

const AMateria* Character::getMateria(int idx) const
{
    if (isValidIndex(idx))
        return materia_[idx];
    else
        return NULL;
}

void Character::unequip(int idx)
{
    if (isValidIndex(idx) && !materia_[idx])
        materia_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (isValidIndex(idx) && !materia_[idx])
        materia_[idx]->use(target);
}
