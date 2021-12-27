#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string const &name);
    ScavTrap(ScavTrap const &other);
    ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &other);

    void attack(const std::string &target);
    void guardGate();

private:
    const static unsigned int kDefaultHp;
    const static unsigned int kDefaultEp;
    const static unsigned int kDefaultAd;
    const static std::string kDefaultName;
};

#endif
