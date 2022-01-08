#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharactor.hpp"

class AMateria
{
protected:
    std::string type_;

public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &other);
    virtual ~AMateria();
    virtual AMateria& operator=(const AMateria&);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

private:
    const static std::string kDefaultType;
};

#endif
