#include "contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::SetContact(const int idx, const std::string info)
{
    this->contact_data[idx] = info;
}

std::string Contact::GetFirstName()
{
    return (contact_data[kFirstName]);
}

std::string Contact::GetLastName()
{
    return (contact_data[kLastName]);
}

std::string Contact::GetNickName()
{
    return (contact_data[kNickName]);
}

std::string Contact::GetPhoneNumber()
{
    return (contact_data[kPhoneNumber]);
}

std::string Contact::GetDarkestSecret()
{
    return (contact_data[kDarkestSecret]);
}
