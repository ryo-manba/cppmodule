#include <string>

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const std::string &type);
    Cure(const Cure &other);
    ~Cure();
    Cure &operator=(const Cure &other);

    AMateria *clone() const;
    void use(ICharacter &target);

private:
    const static std::string kDefaultType;
};
