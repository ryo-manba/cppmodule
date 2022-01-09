#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const std::string & type);
    Ice(const Ice &other);
    ~Ice();
    Ice &operator=(const Ice &other);

    void use(ICharacter &target);
    AMateria *clone() const;

private:
    const static std::string kDefaultType;
};
