#include "Dog.hpp"

#include <iostream>

const std::string Dog::kDefaultType  = "Dog";
const std::string Dog::kDefaultBarks = "bow! wow！";

Dog::Dog() : Animal(kDefaultType)
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const &type) : Animal(type)
{
    std::cout << "Dog " << type << " constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog " << this->Animal::getType() << " destructor called"
              << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
    {
        this->Animal::setType(other.getType());
    }
    return *this;
}

void Dog::makeSound() const { std::cout << kDefaultBarks << std::endl; }
