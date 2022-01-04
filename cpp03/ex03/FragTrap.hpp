#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string const &name);
    FragTrap(FragTrap const &other);
    ~FragTrap();

    FragTrap &operator=(FragTrap const &other);

    void highFivesGuys(void);
    void attack(std::string const &target);

protected:
    const static unsigned int kDefaultHp;
    const static unsigned int kDefaultEp;
    const static unsigned int kDefaultAd;
    const static std::string kDefaultName;
};

#endif
