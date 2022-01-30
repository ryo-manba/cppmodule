#include "DiamondTrap.hpp"

#include <iostream>

const std::string DiamondTrap::kDefaultName = "NONAME";
const unsigned int DiamondTrap::kDefaultHp  = FragTrap::kDefaultHp;
const unsigned int DiamondTrap::kDefaultEp  = ScavTrap::kDefaultEp;
const unsigned int DiamondTrap::kDefaultAd  = FragTrap::kDefaultAd;

DiamondTrap::DiamondTrap()
    : ClapTrap(), _name(kDefaultName)
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    this->ClapTrap::setHitPoints(kDefaultHp);
    this->ClapTrap::setEnergyPoints(kDefaultEp);
    this->ClapTrap::setAttackDamage(kDefaultAd);
    this->ClapTrap::setName(kDefaultName + "_clap_name");
}

DiamondTrap::DiamondTrap(std::string const &name)
    : ClapTrap(), _name(name)
{
    std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
    this->ClapTrap::setHitPoints(kDefaultHp);
    this->ClapTrap::setEnergyPoints(kDefaultEp);
    this->ClapTrap::setAttackDamage(kDefaultAd);
    this->ClapTrap::setName(_name + "_clap_name");
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
        _name = other._name;
        this->ClapTrap::setHitPoints(other.getHitPoints());
        this->ClapTrap::setEnergyPoints(other.getEnergyPoints());
        this->ClapTrap::setAttackDamage(other.getAttackDamage());
        this->ClapTrap::setName(other.ClapTrap::getName());
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap My name is " << _name << ", my ClapTrap name is "
              << this->ClapTrap::getName() << "." << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
    this->ScavTrap::attack(target);
}

const std::string &DiamondTrap::getClapName() const
{
    return this->ClapTrap::getName();
}
const std::string &DiamondTrap::getName() const
{
    return this->_name;
}
