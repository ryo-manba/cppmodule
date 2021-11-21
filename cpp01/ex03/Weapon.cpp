#include "Weapon.hpp"

#include <string>

Weapon::Weapon(std::string const &type) : _type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType() const
{
    return _type;
}

void Weapon::setType(std::string const &type)
{
    _type = type;
}
