#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde( int N, std::string name )
{
    const std::string suffix = "0123456789";
    Zombie *z;

    z = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        z[i].SetName(name + suffix[i % 10]);
    }
    return (z);
}
