#include "HumanB.hpp"

#include <iostream>
#include <string>

HumanB::HumanB(std::string const name) : _name(name) {}

HumanB::~HumanB() {}

void HumanB::attack() const
{
    std::cout << _name << " attacks with his " << _p_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _p_weapon = &weapon;
}
