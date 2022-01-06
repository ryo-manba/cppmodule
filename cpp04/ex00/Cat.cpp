#include "Cat.hpp"

#include <iostream>

const std::string Cat::kDefaultType  = "Cat";
const std::string Cat::kDefaultBarks = "meaw! meaw!";

Cat::Cat() : Animal(kDefaultType)
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const &type) : Animal(type)
{
    std::cout << "Cat " << type << " constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat " << this->Animal::getType() << " destructor called"
              << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
    {
        this->Animal::setType(other.getType());
    }
    return *this;
}

void Cat::makeSound() const { std::cout << kDefaultBarks << std::endl; }
