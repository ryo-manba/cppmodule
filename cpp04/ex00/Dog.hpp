#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(std::string const &type);
    Dog(const Dog &other);
    ~Dog();
    Dog &operator=(Dog const &other);

    void makeSound() const;

private:
    const static std::string kDefaultType;
    const static std::string kDefaultBarks;
};

#endif
