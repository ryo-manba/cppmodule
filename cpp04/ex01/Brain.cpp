#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (std::size_t i = 0; i < kIdeaSize; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

bool Brain::isValidIndex(const size_t &index) const
{
    if (0 <= index && index < kIdeaSize)
        return true;
    else
        return false;
}

void Brain::setIdeas(const size_t &index, const std::string &str)
{
    if (isValidIndex(index))
        ideas[index] = str;
    else
        std::cout << "Error: Out of range" << std::endl;
}

const std::string &Brain::getIdeas(const size_t &index) const
{
    if (isValidIndex(index))
        return ideas[index];
    else
    {
        std::cout << "Error: Out of range" << std::endl;
        return ideas[0];
    }
}

void Brain::showIdeas() const
{
    for (std::size_t i = 0; i < kIdeaSize; i++)
    {
        std::cout << ideas[i] << std::endl;
    }
}
