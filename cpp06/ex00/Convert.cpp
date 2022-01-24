#include "Convert.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

const std::string Convert::kMsgNonDisplay = "Non displayable";
const std::string Convert::kMsgImpossible = "impossible";

// pre message
const std::string Convert::kPreChar   = "char   : ";
const std::string Convert::kPreInt    = "int    : ";
const std::string Convert::kPreFloat  = "float  : ";
const std::string Convert::kPreDouble = "double : ";

Convert::Convert(void)
    : value_(""), c_(0), i_(0), f_(0), d_(0), type_(kTypeDefalut)
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
        default:;
    }
}

Convert::Convert(const Convert& other) { *this = other; }

Convert& Convert::operator=(const Convert& other)
{
    if (this != &other)
    {
        value_ = other.getValue();
        c_     = other.getChar();
        i_     = other.getInt();
        f_     = other.getFloat();
        d_     = other.getDouble();
        type_  = other.getType();
    }
    return *this;
}

Convert::~Convert() {}

const std::string& Convert::getValue(void) const { return value_; }
void Convert::setValue(const std::string& value) { value_ = value; }

// 0,1,2 = double
// 3,4,5 = float
bool Convert::isSpecialValues(const std::string& value)
{
    const std::string specials[6] = {"nan",  "+inf",  "-inf",
                                     "nanf", "+inff", "-inff"};
    for (size_t i = 0; i < 6; ++i)
    {
        if (specials[i] == value)
        {
            if (i < 3)
                type_ = kTypeDouble;
            else
                type_ = kTypeFloat;
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
        if (idx + 1 == len || idx == 0 ||
            ((idx == 1) && (value[idx - 1] == '+' || value[idx - 1] == '-')))
        {
            return false;
        }
        idx += 1;
    }

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
    if (isSpecialValues(value_))
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
    c_ = static_cast<char>(value[0]);
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
    c_ = static_cast<char>(i_);
    f_ = static_cast<float>(i_);
    d_ = static_cast<double>(i_);
}

typeSpecifier Convert::checkSpecialTypes(const std::string& value)
{
    typeSpecifier spType          = kTypeDefalut;
    const std::string specials[3] = {"nan", "+inf", "-inf"};
    for (size_t i = 0; i < 3; ++i)
    {
        if (value == specials[i])
        {
            spType = static_cast<typeSpecifier>(i);
            type_  = kTypeSpecial;
            break;
        }
    }
    return spType;
}

void Convert::convertFloat(const std::string& value)
{
    int specialType = checkSpecialTypes(value);

    switch (specialType)
    {
        case kTypeNan:
            f_ = std::numeric_limits<float>::quiet_NaN();
            break;
        case kTypePInf:
            f_ = std::numeric_limits<float>::infinity();
            break;
        case kTypeNInf:
            f_ = -std::numeric_limits<float>::infinity();
            break;
        case kTypeDefalut:
            std::istringstream iss(value);
            iss >> f_;
            if (!iss)
            {
                type_ = kTypeImpossible;
                return;
            }
    }
    c_ = static_cast<char>(f_);
    i_ = static_cast<int>(f_);
    d_ = static_cast<double>(f_);
}

void Convert::convertDouble(const std::string& value)
{
    int specialType = checkSpecialTypes(value);

    switch (specialType)
    {
        case kTypeNan:
            d_ = std::numeric_limits<double>::quiet_NaN();
            break;
        case kTypePInf:
            d_ = std::numeric_limits<double>::infinity();
            break;
        case kTypeNInf:
            d_ = -std::numeric_limits<double>::infinity();
            break;
        case kTypeDefalut:
            std::istringstream iss(value);
            iss >> d_;
            if (!iss)
            {
                type_ = kTypeImpossible;
                return;
            }
    }
    c_ = static_cast<char>(d_);
    i_ = static_cast<int>(d_);
    f_ = static_cast<float>(d_);
}

// template<typename T>
// bool isOverflow()

void Convert::Print(void) const
{
    if (type_ == kTypeSpecial)
    {
        printChar(kMsgImpossible);
        printInt(kMsgImpossible);
        printFloat(f_);
        printDouble(d_);
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
    if (!(-128 <= i_ && i_ <= 127))
        std::cout << kPreChar << kMsgImpossible << std::endl;
    else if (std::isprint(c))
        std::cout << kPreChar << "'" << c << "'" << std::endl;
    else
        std::cout << kPreChar << kMsgNonDisplay << std::endl;
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
    int tmp = static_cast<int>(f);
    if (f - tmp == 0)
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
    long tmp = static_cast<long>(d);
    if (d - tmp == 0)
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
