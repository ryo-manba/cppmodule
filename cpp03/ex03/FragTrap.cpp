#include "FragTrap.hpp"

#include <iostream>

const std::string FragTrap::kDefaultName = "FRAG_NONAME";
const unsigned int FragTrap::kDefaultHp  = 100;
const unsigned int FragTrap::kDefaultEp  = 100;
const unsigned int FragTrap::kDefaultAd  = 30;

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->ClapTrap::setHitPoints(kDefaultHp);
    this->ClapTrap::setEnergyPoints(kDefaultEp);
    this->ClapTrap::setAttackDamage(kDefaultAd);
    this->ClapTrap::setName(kDefaultName);
}

FragTrap::FragTrap(std::string const &name)
{
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
    this->ClapTrap::setHitPoints(kDefaultHp);
    this->ClapTrap::setEnergyPoints(kDefaultEp);
    this->ClapTrap::setAttackDamage(kDefaultAd);
    this->ClapTrap::setName(name);
}

FragTrap::FragTrap(FragTrap const &other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->ClapTrap::getName() << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
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

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap Good job! High five " << this->ClapTrap::getName() << "!" << std::endl;
}

void FragTrap::attack(std::string const &target)
{
    std::cout << "FragTrap " << this->ClapTrap::getName() << " attack " << target << ", causing "
              << this->ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
}
