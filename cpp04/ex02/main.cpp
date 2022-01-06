#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *animal;
    Animal *animal2;
    // Error: Abstract class cannot be instantiated.
    // Animal animal3;
    // Animal *animal4 = new Animal();

    animal  = new Dog();
    animal2 = new Cat();

    delete animal;
    delete animal2;
    return 0;
}
