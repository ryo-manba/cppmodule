#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(std::string const &type);
    Dog(const Dog &other);
    ~Dog();
    Dog &operator=(Dog const &other);

    void makeSound() const;
    void setIdeas(const size_t &index, const std::string &str);
    const std::string &getIdeas(const size_t &index) const;
    void showIdeas() const;

private:
    const static std::string kDefaultType;
    const static std::string kDefaultBarks;

    Brain *brain_;
};

#endif
