#include "WrongCat.hpp"

#include <iostream>

const std::string WrongCat::kDefaultType  = "WrongCat";
const std::string WrongCat::kDefaultBarks = "wrong! meaw! meaw!";

WrongCat::WrongCat() : WrongAnimal(kDefaultType)
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) { *this = other; }

WrongCat::~WrongCat()
{
    std::cout << "WrongCat " << this->WrongAnimal::getType()
              << " destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

void WrongCat::makeSound() const { std::cout << kDefaultBarks << std::endl; }
