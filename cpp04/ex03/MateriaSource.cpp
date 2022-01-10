#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (size_t i = 0; i < kMaxMateria; i++)
        materias_[i] = NULL;
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
        if (materias_[i])
        {
            delete materias_[i];
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < kMaxMateria; i++)
        {
            delete materias_[i];
            if (other.materias_[i])
                materias_[i] = other.materias_[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        if (materias_[i] == NULL)
        {
            materias_[i] = m;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (size_t i = 0; i < kMaxMateria; i++)
    {
        if (materias_[i] == NULL)
        {
            continue ;
        }
        if (materias_[i]->getType() == type)
        {
            return materias_[i]->clone();
        }
    }
    return NULL;
}
