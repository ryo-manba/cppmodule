#include <climits>
#include <iostream>

#include "DiamondTrap.hpp"

void getInfo(DiamondTrap const &a)
{
    std::cout << "Name: " << a.getName() << std::endl;
    std::cout << "HP  : " << a.getHitPoints() << std::endl;
    std::cout << "EP  : " << a.getEnergyPoints() << std::endl;
    std::cout << "AD  : " << a.getAttackDamage() << std::endl;
}

int main()
{
    DiamondTrap d1("DIAMOND");
    DiamondTrap d2;
    DiamondTrap d3(d1);

    getInfo(d1);
    getInfo(d2);
    getInfo(d3);
    d3 = d2;
    d3.getName();
    d1.attack("ENEMY");

    d1.takeDamage(0);
    d1.takeDamage(1);
    d1.takeDamage(2);
    d1.takeDamage(UINT_MAX);

    d1.beRepaired(0);
    d1.beRepaired(1);
    d1.beRepaired(2);
    d1.beRepaired(UINT_MAX);
    d1.whoAmI();

    return 0;
}
