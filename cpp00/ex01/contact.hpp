#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

#define CONTACT_SIZE 8

enum : int {
    kFirstName,
    kLastName,
    kNickName,
    kPhoneNumber,
    kDarkestSecret
};

class Contact
{
    public:
        Contact();
        ~Contact();

        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();
        std::string GetPhoneNumber();
        std::string GetDarkestSecret();

        void SetFirstName();
        void SetLastName();
        void SetNickName();
        void SetPhoneNumber();
        void SetDarkestSecret();

        void SetContact(const int idx, const std::string info);
        void SearchContact();

    private:
        std::string contact_data[5];
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

};

#endif
