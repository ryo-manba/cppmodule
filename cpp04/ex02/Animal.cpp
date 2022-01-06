#include "Animal.hpp"

#include <iostream>

const std::string Animal::kDefaultType  = "NOTYPE";
const std::string Animal::kDefaultBarks = "ani! mal!";

Animal::Animal() : type(kDefaultType)
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type) : type(type)
{
    std::cout << "Animal " << type << " constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal " << type << " destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

const std::string &Animal::getType() const { return this->type; }

void Animal::setType(std::string const &type) { this->type = type; }
