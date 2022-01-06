#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(std::string const &type);
    Cat(const Cat &other);
    ~Cat();
    Cat &operator=(Cat const &other);

    void makeSound() const;

private:
    const static std::string kDefaultType;
    const static std::string kDefaultBarks;
};

#endif
