#include "Zombie.hpp"

#include <iostream>

#define SCREAMS " BraiiiiiiinnnzzzZ..."

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::Zombie( void ) : _name("Zombie") {}

Zombie::~Zombie( void )
{
    std::cout << _name << " was destroyed" << std::endl; 
}

void Zombie::announce( void )
{
    std::cout << _name << SCREAMS << std::endl;
}