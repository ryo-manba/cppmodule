#include "Karen.hpp"

#include <iostream>

Karen::Karen() {}

Karen::~Karen() {}

void Karen::debug()
{
    std::cout << "I love to get extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                 "just love it!"
              << std::endl;
}

void Karen::info()
{
    std::cout << "I cannot believe adding extra bacon cost more money. You "
                 "don’t put enough! If you did I would not have to ask for it!"
              << std::endl;
}

void Karen::warning()
{
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve been "
           "coming here for years and you just started working here last month."
        << std::endl;
}

void Karen::error()
{
    std::cout << "This is unacceptable, I want to speak to the manager now"
              << std::endl;
}

void Karen::complain(std::string level)
{
    const std::string levels[4]  = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Karen::*func[4])(void) = {&Karen::debug, &Karen::info,
                                    &Karen::warning, &Karen::error};

    int check = (levels[0] == level) * 1 + (levels[1] == level) * 2 +
                (levels[2] == level) * 3 + (levels[3] == level) * 4;

    switch (check)
    {
        case 1:
            (this->*func[0])();
            break;
        case 2:
            (this->*func[1])();
            break;
        case 3:
            (this->*func[2])();
            break;
        case 4:
            (this->*func[3])();
            break;
        default:
            std::cout << "ERROR: Invalid Arguments" << std::endl;
            break;
    }
}
