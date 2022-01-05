#include <climits>
#include <iostream>

#include "FragTrap.hpp"

void getInfo(FragTrap const &a)
{
    std::cout << "Name: " << a.getName() << std::endl;
    std::cout << "HP  : " << a.getHitPoints() << std::endl;
    std::cout << "EP  : " << a.getEnergyPoints() << std::endl;
    std::cout << "AD  : " << a.getAttackDamage() << std::endl;
}

int main()
{
    FragTrap f1("FRAG");
    FragTrap f2;
    FragTrap f3(f1);

    getInfo(f1);
    getInfo(f2);
    getInfo(f3);
    f3 = f2;
    std::cout << "f3 = f2 -> f3 is " << f3.getName() << std::endl;
    f1.attack("ENEMY");

    f1.takeDamage(0);
    f1.takeDamage(1);
    f1.takeDamage(2);
    f1.takeDamage(UINT_MAX);

    f1.beRepaired(0);
    f1.beRepaired(1);
    f1.beRepaired(2);
    f1.beRepaired(UINT_MAX);

    f1.highFivesGuys();
    return 0;
}
