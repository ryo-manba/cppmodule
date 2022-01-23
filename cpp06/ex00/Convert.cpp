#include "Convert.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

const std::string Convert::kMsgNonDisplay     = "Non displayable";
const std::string Convert::kMsgImpossible     = "impossible";
const std::string Convert::kLimits[kNbLimits] = {"nan",   "nanf", "+inf",
                                                 "+inff", "-inf", "-inff"};

// pre message
const std::string Convert::kPreChar   = "char   :";
const std::string Convert::kPreInt    = "int    :";
const std::string Convert::kPreFloat  = "float  :";
const std::string Convert::kPreDouble = "double :";

Convert::Convert(void)
    : value_(""),
      c_(0),
      i_(0),
      f_(0),
      d_(0),
      type_(kTypeDefalut),
      isDisplayableFlag_(true),
      allZeroFlag_(true)
{
}

Convert::Convert(const std::string& value) : value_(value)
{
    type_ = parseType();

    switch (type_)
    {
        case kTypeChar:
            convertChar(value_);
            break;
        case kTypeInt:
            convertInt(value_);
            break;
        case kTypeFloat:
            value_ = value_.substr(0, value.length() - 1);
            convertFloat(value_);
            break;
        case kTypeDouble:
            convertDouble(value_);
            break;
        case kTypeImpossible:
            break;
        default:
            ;
    }
}

Convert::Convert(const Convert& other) { *this = other; }

Convert& Convert::operator=(const Convert& other)
{
    if (this != &other)
    {
        value_             = other.getValue();
        c_                 = other.getChar();
        i_                 = other.getInt();
        f_                 = other.getFloat();
        d_                 = other.getDouble();
        type_              = other.getType();
        isDisplayableFlag_ = other.getIsDisplayableFlag();
        allZeroFlag_       = other.getAllZeroFlag();
    }
    return *this;
}

Convert::~Convert() {}

const std::string& Convert::getValue(void) const { return value_; }

void Convert::setValue(const std::string& value) { value_ = value; }

bool Convert::isInfOrNan(const std::string& value)
{
    for (size_t i = 0; i < kNbLimits; i++)
    {
        if (kLimits[i] == value)
        {
            type_ = static_cast<typeSpecifier>(i / 2);
            return true;
        }
    }
    return false;
}

bool Convert::isChar(const std::string& value) const
{
    if (value.length() == 1)
    {
        if (std::isdigit(value[0]) == false && std::isprint(value[0]))
        {
            return true;
        }
    }
    return false;
}

bool Convert::isInt(const std::string& value) const
{
    size_t len = value.length();
    size_t idx = 0;
    if (value[idx] == '+' || value[idx] == '-')
    {
        idx += 1;
    }
    while (std::isdigit(value[idx]))
    {
        idx += 1;
    }
    if (idx == len)
    {
        return true;
    }
    return false;
}

bool Convert::isAllZero(const std::string& value, size_t idx)
{
    while (std::isdigit(value[idx]))
    {
        if (value[idx] != '0')
        {
            return false;
        }
        idx += 1;
    }
    return true;
}

bool Convert::isFloatOrDouble(const std::string& value)
{
    size_t len = value.length();
    size_t idx = 0;

    if (value[idx] == '+' || value[idx] == '-')
    {
        idx += 1;
    }
    while (std::isdigit(value[idx]))
    {
        idx += 1;
    }
    if (value[idx] == '.')
    {
        if (idx + 1 == len || idx == 0 || \
            ((idx == 1) && (value[idx - 1] == '+' || value[idx - 1] == '-')))
        {
            return false;
        }
        idx += 1;
    }

    allZeroFlag_ = isAllZero(value, idx);
    while (std::isdigit(value[idx]))
    {
        idx += 1;
    }
    if (idx == len)
    {
        type_ = kTypeDouble;
        return true;
    }
    if (value[idx] == 'f' && std::isdigit(value[idx - 1]) && idx == len - 1)
    {
        type_ = kTypeFloat;
        return true;
    }
    return false;
}

typeSpecifier Convert::parseType(void)
{
    if (isInfOrNan(value_))
    {
        return type_;
    }
    if (isChar(value_))
    {
        return kTypeChar;
    }
    if (isInt(value_))
    {
        return kTypeInt;
    }
    if (isFloatOrDouble(value_))
    {
        return type_;
    }
    return kTypeImpossible;
}

void Convert::convertChar(const std::string& value)
{
    std::istringstream iss(value);
    iss >> c_;

    if (!iss)
    {
        type_ = kTypeImpossible;
        return;
    }
    i_ = static_cast<int>(c_);
    f_ = static_cast<float>(c_);
    d_ = static_cast<double>(c_);
}

void Convert::convertInt(const std::string& value)
{
    std::istringstream iss(value);
    iss >> i_;

    if (!iss)
    {
        type_ = kTypeImpossible;
        return;
    }
    else if (std::isprint(i_))
    {
        c_ = static_cast<char>(i_);
    }
    else
    {
        isDisplayableFlag_ = false;
    }
    f_ = static_cast<float>(i_);
    d_ = static_cast<double>(i_);
}

void Convert::convertFloat(const std::string& value)
{
    std::istringstream iss(value);
    iss >> f_;

    if (!iss)
    {
        type_ = kTypeImpossible;
        return;
    }
    else if (std::isprint(f_))
    {
        c_ = static_cast<char>(f_);
    }
    else
    {
        isDisplayableFlag_ = false;
    }
    i_ = static_cast<int>(f_);
    d_ = static_cast<double>(f_);
}

void Convert::convertDouble(const std::string& value)
{
    std::istringstream iss(value);
    iss >> d_;

    if (!iss)
    {
        type_ = kTypeImpossible;
    }
    else if (std::isprint(d_))
    {
        c_ = static_cast<char>(d_);
    }
    else
    {
        isDisplayableFlag_ = false;
    }
    i_ = static_cast<int>(d_);
    f_ = static_cast<float>(d_);
}

void Convert::Print(void) const
{
    const std::string limits[3] = {"nan", "+inf", "-inf"};
    if (type_ <= kTypeNInf)
    {
        printChar(kMsgImpossible);
        printInt(kMsgImpossible);
        printFloat(limits[type_]);
        printDouble(limits[type_]);
    }
    else if (type_ == kTypeImpossible)
    {
        printChar(kMsgImpossible);
        printInt(kMsgImpossible);
        printFloat(kMsgImpossible);
        printDouble(kMsgImpossible);
    }
    else
    {
        printChar(c_);
        printInt(i_);
        printFloat(f_);
        printDouble(d_);
    }
}

// print
void Convert::printChar(const char& c) const
{
    if (isDisplayableFlag_ == false)
    {
        std::cout << kPreChar << kMsgNonDisplay << std::endl;
    }
    else
    {
        std::cout << kPreChar << "'" << c << "'" << std::endl;
    }
}

void Convert::printChar(const std::string& msg) const
{
    std::cout << kPreChar << msg << std::endl;
}

void Convert::printInt(const int& i) const
{
    std::cout << kPreInt << i << std::endl;
}

void Convert::printInt(const std::string& msg) const
{
    std::cout << kPreInt << msg << std::endl;
}

void Convert::printFloat(const float& f) const
{
    if (type_ == kTypeInt || type_ == kTypeChar || allZeroFlag_ == true)
    {
        std::cout << kPreFloat << f << ".0f" << std::endl;
    }
    else
    {
        std::cout << kPreFloat << f << "f" << std::endl;
    }
}

void Convert::printFloat(const std::string& msg) const
{
    std::cout << kPreFloat << msg;
    if (msg == kMsgImpossible)
    {
        std::cout << std::endl;
    }
    else
        std::cout << "f" << std::endl;
}

void Convert::printDouble(const double& d) const
{
    if (type_ == kTypeInt || type_ == kTypeChar || allZeroFlag_ == true)
    {
        std::cout << kPreDouble << d << ".0" << std::endl;
    }
    else
    {
        std::cout << kPreDouble << d << std::endl;
    }
}

void Convert::printDouble(const std::string& msg) const
{
    std::cout << kPreDouble << msg << std::endl;
}

// getter
const char& Convert::getChar(void) const { return c_; }
const int& Convert::getInt(void) const { return i_; }
const float& Convert::getFloat(void) const { return f_; }
const double& Convert::getDouble(void) const { return d_; }
const typeSpecifier& Convert::getType(void) const { return type_; }
const bool& Convert::getIsDisplayableFlag(void) const
{
    return isDisplayableFlag_;
}
const bool& Convert::getAllZeroFlag(void) const { return allZeroFlag_; }
