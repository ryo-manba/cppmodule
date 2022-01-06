#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    Animal(std::string type);
    virtual ~Animal();
    Animal &operator=(Animal const &other);

    const std::string &getType() const;
    void setType(std::string const &type);

    virtual void makeSound() const = 0;

protected:
    std::string type;

private:
    const static std::string kDefaultType;
    const static std::string kDefaultBarks;
};

#endif
