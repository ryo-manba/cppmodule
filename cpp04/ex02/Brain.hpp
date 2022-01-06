#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
public:
    Brain();
    Brain(const Brain &other);
    ~Brain();
    Brain &operator=(const Brain &other);

    const std::string &getIdeas(const size_t &index) const;
    void setIdeas(const size_t &index, const std::string &str);
    void showIdeas() const;

private:
    static const size_t kIdeaSize = 100;
    std::string ideas[kIdeaSize];
    bool isValidIndex(const size_t &index) const;
};

#endif
