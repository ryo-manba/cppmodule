#include <climits>
#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void getInfo(ScavTrap const &a)
{
    std::cout << "Name: " << a.getName() << std::endl;
    std::cout << "HP  : " << a.getHitPoints() << std::endl;
    std::cout << "EP  : " << a.getEnergyPoints() << std::endl;
    std::cout << "AD  : " << a.getAttackDamage() << std::endl;
}

int main()
{
    ScavTrap s1("SCAV");
    ScavTrap s2;
    ScavTrap s3(s1);

    getInfo(s1);
    getInfo(s2);
    getInfo(s3);
    s3 = s2;
    s3.getName();
    s1.attack("ENEMY");
    s1.takeDamage(0);
    s1.takeDamage(1);
    s1.takeDamage(2);
    s1.takeDamage(UINT_MAX);
    s1.beRepaired(0);
    s1.beRepaired(1);
    s1.beRepaired(2);
    s1.beRepaired(UINT_MAX);
    s1.guardGate();
    return 0;
}
