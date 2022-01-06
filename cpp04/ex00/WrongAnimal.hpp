#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal(const std::string &type);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &other);

    const std::string &getType() const;

    void makeSound() const;

protected:
    std::string type;

private:
    const static std::string kDefaultType;
    const static std::string kDefaultBarks;
};
#endif
