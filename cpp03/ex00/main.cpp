#include <climits>
#include <iostream>

#include "ClapTrap.hpp"

void getInfo(ClapTrap const &a)
{
    std::cout << "Name: " << a.getName() << std::endl;
    std::cout << "HP  : " << a.getHitPoints() << std::endl;
    std::cout << "EP  : " << a.getEnergyPoints() << std::endl;
    std::cout << "AD  : " << a.getAttackDamage() << std::endl;
}
int main()
{
    ClapTrap c1("CLAP");
    ClapTrap c2;
    ClapTrap c3(c1);

    getInfo(c1);
    getInfo(c2);
    getInfo(c3);
    c3 = c2;
    c3.getName();
    c1.attack("ENEMY");
    c1.takeDamage(0);
    c1.takeDamage(1);
    c1.takeDamage(2);
    c1.takeDamage(UINT_MAX);
    c1.beRepaired(0);
    c1.beRepaired(1);
    c1.beRepaired(2);
    c1.beRepaired(UINT_MAX);

    return 0;
}
