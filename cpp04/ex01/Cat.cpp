#include "Cat.hpp"

#include <iostream>

const std::string Cat::kDefaultType  = "Cat";
const std::string Cat::kDefaultBarks = "meaw! meaw!";

Cat::Cat() : Animal(kDefaultType), brain_(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const &type) : Animal(type), brain_(new Brain())
{
    std::cout << "Cat " << type << " constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat " << this->Animal::getType() << " destructor called"
              << std::endl;
    if (brain_) delete brain_;
}

Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
    {
        this->Animal::setType(other.getType());
        brain_ = new Brain(*(other.brain_));
    }
    return *this;
}

void Cat::makeSound() const { std::cout << kDefaultBarks << std::endl; }

void Cat::setIdeas(const size_t &index, const std::string &str)
{
    this->brain_->setIdeas(index, str);
}

const std::string &Cat::getIdeas(const size_t &index) const
{
    return this->brain_->getIdeas(index);
}
