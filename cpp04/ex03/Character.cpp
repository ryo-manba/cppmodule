#include "Character.hpp"

#include <iostream>

const std::string Character::kDefaultName = "NONAME";

Character::Character() : name_(kDefaultName)
{
    for (size_t i = 0; i < kMaxMateria; i++) materias_[i] = NULL;
}

Character::Character(std::string const &name) : name_(name)
{
    for (size_t i = 0; i < kMaxMateria; i++) materias_[i] = NULL;
}

Character::Character(const Character &other) { *this = other; }

Character::~Character()
{
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        if (materias_[i])
        {
            delete materias_[i];
        }
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < kMaxMateria; i++)
        {
            delete materias_[i];
        }
        for (size_t i = 0; i < kMaxMateria; i++)
        {
            if (other.materias_[i])
                materias_[i] = other.materias_[i]->clone();
            else
                materias_[i] = NULL;
        }
    }
    return *this;
}

std::string const &Character::getName() const { return name_; }

void Character::equip(AMateria *m)
{
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        if (materias_[i] == NULL)
        {
            materias_[i] = m;
            return;
        }
    }
}

bool Character::isValidIndex(int idx) const
{
    return 0 <= idx && idx < static_cast<int>(kMaxMateria);
}

void Character::unequip(int idx)
{
    if (isValidIndex(idx) && materias_[idx]) materias_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (isValidIndex(idx) && materias_[idx]) materias_[idx]->use(target);
}
