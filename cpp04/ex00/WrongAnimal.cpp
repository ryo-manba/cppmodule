#include "WrongAnimal.hpp"

#include <iostream>

const std::string WrongAnimal::kDefaultType  = "NOTYPE";
const std::string WrongAnimal::kDefaultBarks = "wrong! ani! mal!";

WrongAnimal::WrongAnimal() : type(kDefaultType)
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
    std::cout << "WrongAnimal " << type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " << type << " destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

const std::string &WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const { std::cout << kDefaultBarks << std::endl; }
