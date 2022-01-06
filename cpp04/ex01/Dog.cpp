#include "Dog.hpp"

#include <iostream>

const std::string Dog::kDefaultType  = "Dog";
const std::string Dog::kDefaultBarks = "bow! wow！";

Dog::Dog() : Animal(kDefaultType), brain_(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const &type) : Animal(type), brain_(new Brain())
{
    std::cout << "Dog " << type << " constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog " << this->Animal::getType() << " destructor called"
              << std::endl;
    if (brain_) delete brain_;
}

Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
    {
        this->Animal::setType(other.getType());

        delete brain_;
        brain_ = new Brain(*(other.brain_));
    }
    return *this;
}

void Dog::makeSound() const { std::cout << kDefaultBarks << std::endl; }

void Dog::setIdeas(const size_t &index, const std::string &str)
{
    this->brain_->setIdeas(index, str);
}

const std::string &Dog::getIdeas(const size_t &index) const
{
    return this->brain_->getIdeas(index);
}
