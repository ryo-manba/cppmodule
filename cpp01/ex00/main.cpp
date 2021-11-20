#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
    Zombie* z;

    z = newZombie("Zonbie");
    z->announce();
    randomChump("xxxx");
    delete(z); // deleteしないとデストラクタよばれない
    return 0;
}