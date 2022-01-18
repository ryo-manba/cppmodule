#include "Convert.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

#define debug(s) std::cout << #s << " : " << s << std::endl;

const std::string Convert::kMsgNonDisplay = "Non displayable";
const std::string Convert::kMsgImpossible = "impossible";


Convert::Convert(void) : value_(""), c_(0), i_(0), f_(0), d_(0)
{
}

Convert::Convert(const std::string &value) : value_(value)
{
    type_ = parseType();
    debug(type_);

    switch(type_)
    {
        case kTypeChar:
            convertChar(value_);
            break;
        case kTypeInt:
            convertInt(value_);
            break;
        case kTypeFloat:
            convertFloat(value_);
            break;
        case kTypeDouble:
            convertDouble(value_);
            break;
        case kTypeImpossible:
            break;
        default:
    }
    Print();
}

Convert::Convert(const Convert &other)
{
    *this = other;
}

Convert &Convert::operator=(const Convert &other)
{
    if (this != &other)
    {
        value_ = other.getValue();
    }
    return *this;
}

Convert::~Convert()
{
}

const std::string& Convert::getValue(void) const
{
    return value_;
}

void Convert::setValue(const std::string &value)
{
    value_ = value;
}

typeSpecifier Convert::parseType(void)
{
    size_t len = value_.length();
    if (len == 1)
    {
        if (std::isdigit(value_[0]) == false && std::isprint(value_[0]))
        {
            return kTypeChar;
        }
    }

    if (std::isdigit(value_[0]) == false)
        return kTypeImpossible;

    int dot = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (value_[i] == '.')
        {
            dot += 1;
            if (dot == 2)
            {
                return kTypeImpossible;
            }
            continue;
        }

        if (std::isdigit(value_[i]) == false)
        {
            if ((len - 1 == i) && value_[i] == 'f')
            {
                value_ = value_.substr(0, len - 1);
                return kTypeFloat;
            }
            return kTypeImpossible;
        }
    }
    if (dot == 1)
    {
        return kTypeDouble;
    }
    return kTypeInt;
}

void Convert::convertChar(const std::string& value)
{
    std::istringstream iss(value);
    iss >> c_;

    if (iss)
    {
        ;
    }
    else // error
    {
        ;
    }

    i_ = static_cast<int>(c_);
    f_ = static_cast<float>(c_);
    d_ = static_cast<double>(c_);
}

void Convert::convertInt(const std::string& value)
{
    std::istringstream iss(value);
    iss >> i_;

    if (std::isprint(i_))
    {
        c_ = static_cast<char>(i_);
    }
    else
    {
        c_ = kErrNonDisplay;
    }
    f_ = static_cast<float>(i_);
    d_ = static_cast<double>(i_);
}

void Convert::convertFloat(const std::string& value)
{
    std::istringstream iss(value);
    iss >> f_;
    debug(value);
    debug(f_);

    if (std::isprint(f_))
    {
        c_ = static_cast<char>(f_);
    }
    else
    {
        c_ = kErrNonDisplay;
    }
    i_ = static_cast<int>(f_);
    d_ = static_cast<double>(f_);
}

void Convert::convertDouble(const std::string& value)
{
    std::istringstream iss(value);
    iss >> d_;

    if (std::isprint(d_))
    {
        c_ = static_cast<char>(d_);
    }
    else
    {
        c_ = kErrNonDisplay;
    }

    i_ = static_cast<int>(d_);
    f_ = static_cast<float>(d_);
}

void Convert::Print(void) const
{
    if (c_ == kErrNonDisplay)
    {
        std::cout << "char   : " << kMsgNonDisplay << std::endl;
    }
    else
    {
        std::cout << "char   : " << "'" << c_ << "'" << std::endl;
    }
    std::cout << "int    : " << i_ << std::endl;
    std::cout << "float  : " << std::setprecision(10)  << f_ << "f" << std::endl;
    std::cout << "double : " << std::setprecision(10)  << d_  << std::endl;
}
