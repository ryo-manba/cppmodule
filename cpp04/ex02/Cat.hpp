#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(std::string const &type);
    Cat(const Cat &other);
    ~Cat();
    Cat &operator=(Cat const &other);

    void setIdeas(const size_t &index, const std::string &str);
    const std::string &getIdeas(const size_t &index) const;
    void makeSound() const;

private:
    const static std::string kDefaultType;
    const static std::string kDefaultBarks;

    Brain *brain_;
};

#endif
