#include "Zombie.hpp"

int main(void)
{
    Zombie* z;

    z = newZombie("Dynamic zombie");
    z->announce();
    randomChump("Static zombie");
    delete(z);
    return (0);
}
