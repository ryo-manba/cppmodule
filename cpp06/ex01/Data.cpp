#include "Data.hpp"

#include <iostream>

Data::Data(void) : name_("NONAME"), value_(0)
{}
Data::Data(const std::string& name, const int& value) : name_(name), value_(value)
{}

Data::Data(const Data& other) { *this = other; }

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        name_  = other.getName();
        value_ = other.getValue();
    }
    return *this;
}

Data::~Data(void) {}

void Data::Print(void) const
{
    std::cout << "address : " << this << "\n"
              << "name    : " << name_ << "\n"
              << "value   : " << value_ << std::endl;
}

const std::string& Data::getName(void) const { return name_; }
const int& Data::getValue(void) const { return value_; }

void Data::setName(const std::string& name) { name_ = name; }
void Data::setValue(const int& value) { value_ = value; }
