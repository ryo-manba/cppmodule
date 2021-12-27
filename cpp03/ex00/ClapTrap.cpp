#include "ClapTrap.hpp"

#include <climits>
#include <iostream>

const std::string ClapTrap::kDefaultName = "NONAME";
const unsigned int ClapTrap::kDefaultHp = 10;
const unsigned int ClapTrap::kDefaultEp = 10;
const unsigned int ClapTrap::kDefaultAd = 0;

ClapTrap::ClapTrap() :
    _name(kDefaultName),
    _hitPoints(kDefaultHp),
    _energyPoints(kDefaultEp),
    _attackDamage(kDefaultAd)
{

    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) :
    _name(name),
    _hitPoints(kDefaultHp),
    _energyPoints(kDefaultEp),
    _attackDamage(kDefaultAd)
{
    std::cout << _name << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "copy constructor called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << _name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    if (this != &other)
    {
        _name         = other._name;
        _hitPoints    = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(std::string const &target)
{
    std::cout << "ClapTrap " << _name << " attack " << target << ", causing "
              << _attackDamage << "points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints < amount) _hitPoints = 0;
    else _hitPoints = _hitPoints - amount;
    std::cout << "ClapTrap " << _name << " taken " << amount
              << " damage, so it has " << _hitPoints << " HP remaining."
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > _hitPoints + amount) _hitPoints = UINT_MAX;
    else _hitPoints = _hitPoints + amount;
    std::cout << "ClapTrap " << _name << " is repaired " << amount
              << ", so it has " << _hitPoints << " HP remaining." << std::endl;
}

const std::string& ClapTrap::getName()   const { return _name; };
unsigned int ClapTrap::getHitPoints()    const { return _hitPoints; };
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; };
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; };
