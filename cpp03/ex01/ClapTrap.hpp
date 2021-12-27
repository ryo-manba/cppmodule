#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string const &name);
    ClapTrap(ClapTrap const &other);
    virtual ~ClapTrap();

    ClapTrap &operator=(ClapTrap const &other);

    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    const std::string &getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;

protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

private:
    const static unsigned int kDefaultHp;
    const static unsigned int kDefaultEp;
    const static unsigned int kDefaultAd;
    const static std::string kDefaultName;
};

#endif
