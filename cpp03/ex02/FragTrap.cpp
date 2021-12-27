#include "FragTrap.hpp"

#include <iostream>

const std::string FragTrap::kDefaultName = "NONAME";
const unsigned int FragTrap::kDefaultHp  = 100;
const unsigned int FragTrap::kDefaultEp  = 100;
const unsigned int FragTrap::kDefaultAd  = 30;

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    _name         = kDefaultName;
    _hitPoints    = kDefaultHp;
    _energyPoints = kDefaultEp;
    _attackDamage = kDefaultAd;
}

FragTrap::FragTrap(std::string const &name)
{
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
    _name         = name;
    _hitPoints    = kDefaultHp;
    _energyPoints = kDefaultEp;
    _attackDamage = kDefaultAd;
}

FragTrap::FragTrap(const FragTrap &other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    if (this != &other)
    {
        _name         = other.getName();
        _hitPoints    = other.getHitPoints();
        _energyPoints = other.getEnergyPoints();
        _attackDamage = other.getAttackDamage();
    }
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap Good job! High five " << _name << "!" << std::endl;
}
