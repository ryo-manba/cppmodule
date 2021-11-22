#include "Karen.hpp"

#include <iostream>

Karen::Karen() {}

Karen::~Karen() {}

void Karen::debug()
{
    std::cout << "[ DEBUG ] " << std::endl
              << "I love to get extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger.\nI "
                 "just love it!\n"
              << std::endl;
}

void Karen::info()
{
    std::cout
        << "[ INFO ] " << std::endl
        << "I cannot believe adding extra bacon cost more money.\nYou "
           "don’t put enough! If you did I would not have to ask for it!\n"
        << std::endl;
}

void Karen::warning()
{
    std::cout
        << "[ WARNING ] " << std::endl
        << "I think I deserve to have some extra bacon for free.\nI’ve been "
           "coming here for years and you just started working here last "
           "month.\n"
        << std::endl;
}

void Karen::error()
{
    std::cout << "[ ERROR ] " << std::endl
              << "This is unacceptable, I want to speak to the manager now.\n"
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
        case 2:
            (this->*func[1])();
        case 3:
            (this->*func[2])();
        case 4:
            (this->*func[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n"
                      << std::endl;
            break;
    }
}
