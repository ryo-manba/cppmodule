#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void wrongTest()
{
    std::cout << "\n-----Wrong Animal Test-----" << std::endl;
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i    = new WrongCat();
    std::cout << "-----getType()------" << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "-----makeSound()-----" << std::endl;
    i->makeSound();    // will output the cat sound!
    meta->makeSound();
    delete i;
    delete meta;
}

int main()
{
    const Animal* meta = new Animal();
    const Animal* j    = new Dog();
    const Animal* i    = new Cat();
    std::cout << "-----getType()------" << std::endl;
    std::cout << "Dog = " << j->getType() << " " << std::endl;
    std::cout << "Cat = " << i->getType() << " " << std::endl;

    std::cout << "-----makeSound()-----" << std::endl;
    i->makeSound();    // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    wrongTest();

    delete i;
    delete j;
    delete meta;
    return 0;
}
