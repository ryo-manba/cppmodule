#include "HumanA.hpp"

#include <iostream>
#include <string>

HumanA::HumanA(std::string const name, Weapon const &weapon)
    : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA() {}

void HumanA::attack() const
{
    std::cout << _name << " attacks with his " << _weapon.getType()
              << std::endl;
}
