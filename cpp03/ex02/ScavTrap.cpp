#include "ScavTrap.hpp"

#include <iostream>

const std::string ScavTrap::kDefaultName = "NONAME";
const unsigned int ScavTrap::kDefaultHp  = 100;
const unsigned int ScavTrap::kDefaultEp  = 50;
const unsigned int ScavTrap::kDefaultAd  = 20;

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    _name         = kDefaultName;
    _hitPoints    = kDefaultHp;
    _energyPoints = kDefaultEp;
    _attackDamage = kDefaultAd;
}

ScavTrap::ScavTrap(std::string const &name)
{
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    _name         = name;
    _hitPoints    = kDefaultHp;
    _energyPoints = kDefaultEp;
    _attackDamage = kDefaultAd;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
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

void ScavTrap::attack(std::string const &target)
{
    std::cout << "ScavTrap " << _name << " attack " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << "have enterred in Gate keeper mode."
              << std::endl;
}
