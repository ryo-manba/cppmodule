#include "ScavTrap.hpp"

#include <iostream>

const std::string ScavTrap::kDefaultName = "SCAV_NONAME";
const unsigned int ScavTrap::kDefaultHp  = 100;
const unsigned int ScavTrap::kDefaultEp  = 50;
const unsigned int ScavTrap::kDefaultAd  = 20;

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->ClapTrap::setHitPoints(kDefaultHp);
    this->ClapTrap::setEnergyPoints(kDefaultEp);
    this->ClapTrap::setAttackDamage(kDefaultAd);
    this->ClapTrap::setName(kDefaultName);
}

ScavTrap::ScavTrap(std::string const &name)
{
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    this->ClapTrap::setHitPoints(kDefaultHp);
    this->ClapTrap::setEnergyPoints(kDefaultEp);
    this->ClapTrap::setAttackDamage(kDefaultAd);
    this->ClapTrap::setName(name);
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->ClapTrap::getName() << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    if (this != &other)
    {
        this->ClapTrap::setHitPoints(other.getHitPoints());
        this->ClapTrap::setEnergyPoints(other.getEnergyPoints());
        this->ClapTrap::setAttackDamage(other.getAttackDamage());
        this->ClapTrap::setName(other.ClapTrap::getName());
    }
    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    std::cout << "ScavTrap " << this->ClapTrap::getName() << " attack " << target << ", causing "
              << this->ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->ClapTrap::getName() << "have enterred in Gate keeper mode."
              << std::endl;
}
