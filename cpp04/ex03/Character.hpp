#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"


class Character : public ICharacter
{
public:
    Character();
    Character(const std::string & name);
    Character(const Character &other);
    ~Character();
    Character &operator=(const Character &other);

    virtual std::string const &getName() const;
    const AMateria* getMateria(int idx) const;

    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

private:
    static const std::string kDefaultName;
    static const size_t kMaxMateria = 4;
    bool isValidIndex(int idx) const;
    AMateria *materia_[kMaxMateria];
    std::string name_;
};


#endif
