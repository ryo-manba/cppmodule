#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Phonebook
{
    private:
        const int MAX = 8;
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone;
        std::string _number;
        std::string _darkest_secret;

    public:
        void    set_first_name();
        void    set_last_name();
        void    set_nickname();
        void    set_phone();
        void    set_number();
        void    set_darkest_secret();

        void    get_first_name();
        void    get_last_name();
        void    get_nickname();
        void    get_phone();
        void    get_number();
        void    get_darkest_secret();

};

#endif