#include "Zombie.hpp"

#define NB 10

int main(void)
{
    Zombie *z;

    z = zombieHorde(NB, "zombie");
    for (int i = 0; i < NB; i++)
    {
        z[i].announce();
    }
    delete []z;
    return (0);
}
