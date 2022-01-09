#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &other);

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);

private:
    static const size_t kMaxMateria = 4;
    AMateria *materia_[kMaxMateria];
};


#endif
