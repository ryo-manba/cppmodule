#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *animal1;
    Animal *animal2;
    // Error: Abstract class cannot be instantiated.
    // Animal animal3;
    // Animal *animal4 = new Animal();

    animal1 = new Dog();
    animal2 = new Cat();

    animal1->makeSound();
    animal2->makeSound();

    delete animal1;
    delete animal2;
    return 0;
}
