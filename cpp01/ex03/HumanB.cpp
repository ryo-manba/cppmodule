#include "HumanB.hpp"

#include <iostream>
#include <string>

HumanB::HumanB(std::string const name) : _name(name), _weapon("weapon") {}

HumanB::~HumanB() {}

void HumanB::attack()
{
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
    _weapon = weapon;
}
