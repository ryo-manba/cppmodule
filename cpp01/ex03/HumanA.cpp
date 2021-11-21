#include "HumanA.hpp"

#include <iostream>
#include <string>

HumanA::HumanA(std::string const name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA() {}

void HumanA::attack()
{
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
