#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (size_t i = 0; i < kMaxMateria; i++)
        materia_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = other;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        if (materia_[i])
        {
            delete materia_[i];
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < kMaxMateria; i++)
        {
            delete materia_[i];
            if (other.materia_[i])
                materia_[i] = other.materia_[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
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

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        if (materia_[i] == NULL)
        {
            continue ;
        }
        if (materia_[i]->getType() == type)
        {
            return materia_[i]->clone();
        }
    }
    return NULL;
}
