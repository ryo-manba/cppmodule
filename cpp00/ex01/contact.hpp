#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#define DATA_MAX_USER_ID 8

class Contact
{
    public:
        Contact();
        ~Contact();

        void PrintList(const int id);
        void PrintData();
        bool SetContact(const int id, const std::string info);
        static bool IsDigit(const char c);

    private:
        std::string info_[5];
};

#endif
