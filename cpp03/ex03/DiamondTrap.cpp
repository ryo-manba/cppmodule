#include "DiamondTrap.hpp"

#include <iostream>

const std::string DiamondTrap::kDefaultName = "NONAME";
const unsigned int DiamondTrap::kDefaultHp  = FragTrap::kDefaultHp;
const unsigned int DiamondTrap::kDefaultEp  = ScavTrap::kDefaultEp;
const unsigned int DiamondTrap::kDefaultAd  = FragTrap::kDefaultAd;

DiamondTrap::DiamondTrap()
    :  ClapTrap(kDefaultName + "_clap_name"), _name(kDefaultName)
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _hitPoints    = kDefaultHp;
    _energyPoints = kDefaultEp;
    _attackDamage = kDefaultAd;
}

DiamondTrap::DiamondTrap(std::string const &name)
    : ClapTrap(name + "_clap_name"), _name(name)
{
    std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
    _hitPoints    = kDefaultHp;
    _energyPoints = kDefaultEp;
    _attackDamage = kDefaultAd;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
    if (this != &other)
    {
        _name                = other.getName();
        _hitPoints           = other.getHitPoints();
        _energyPoints        = other.getEnergyPoints();
        _attackDamage        = other.getAttackDamage();
        this->ClapTrap::_name = other.ClapTrap::_name;
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap My name is " << _name << ", my ClapTrap name is "
              << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
    this->ScavTrap::attack(target);
}

const std::string DiamondTrap::getClapName() const
{
    return this->ClapTrap::name;
}
