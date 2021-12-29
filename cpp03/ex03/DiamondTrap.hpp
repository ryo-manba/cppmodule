#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    DiamondTrap();
    DiamondTrap(std::string const &name);
    DiamondTrap(DiamondTrap const &other);
    ~DiamondTrap();

    DiamondTrap &operator=(DiamondTrap const &other);

    void whoAmI(void);
    void attack(std::string const &target);

    const std::string &getClapName() const;

private:
    const static unsigned int kDefaultHp;
    const static unsigned int kDefaultEp;
    const static unsigned int kDefaultAd;
    const static std::string kDefaultName;

    std::string _name;
};
#endif
