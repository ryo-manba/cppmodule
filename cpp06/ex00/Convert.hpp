#ifndef CONVERT_HPP
#define CONVERT_HPP

enum typeSpecifier
{
    kTypeChar,
    kTypeInt,
    kTypeFloat,
    kTypeDouble,
    kTypeImpossible
};

enum typeError
{
    kErrNonDisplay = -1
};

#include <string>
class Convert
{
public:
    Convert();
    Convert(const Convert &other);
    Convert(const std::string &value);
    Convert &operator=(const Convert &other);
    ~Convert();

    const std::string& getValue(void) const;
    void setValue(const std::string &value);
    void Print(void) const;

private:
    const static std::string kMsgNonDisplay;
    const static std::string kMsgImpossible;

    std::string value_;
    typeSpecifier type_;
    char c_;
    int i_;
    float f_;
    double d_;

    bool isDigit(const char& c) const;

    typeSpecifier parseType(void);
    void convertChar(const std::string& value);
    void convertInt(const std::string& value);
    void convertFloat(const std::string& value);
    void convertDouble(const std::string& value);
};

#endif
