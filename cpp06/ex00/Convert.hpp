#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

enum typeSpecifier
{
    kTypeNan,
    kTypePInf,
    kTypeNInf,
    kTypeChar,
    kTypeInt,
    kTypeFloat,
    kTypeDouble,
    kTypeImpossible,
    kTypeSpecial,
    kTypeDefalut
};

class Convert
{
public:
    Convert();
    Convert(const Convert& other);
    Convert(const std::string& value);
    Convert& operator=(const Convert& other);
    ~Convert();

    const std::string& getValue(void) const;
    void setValue(const std::string& value);
    void Print(void) const;

private:
    const static std::string kMsgNonDisplay;
    const static std::string kMsgImpossible;

    const static std::string kPreChar;
    const static std::string kPreInt;
    const static std::string kPreFloat;
    const static std::string kPreDouble;

    std::string value_;
    char c_;
    int i_;
    float f_;
    double d_;
    typeSpecifier type_;

    typeSpecifier parseType(void);

    bool isChar(const std::string& value) const;
    bool isInt(const std::string& value) const;
    bool isFloatOrDouble(const std::string& value);
    bool isAllZero(const std::string& value, size_t idx);
    bool isSpecialValues(const std::string& value);

    typeSpecifier checkSpecialTypes(const std::string& value);

    void convertChar(const std::string& value);
    void convertInt(const std::string& value);
    void convertFloat(const std::string& value);
    void convertDouble(const std::string& value);

    // print
    void printChar(const char& c) const;
    void printChar(const std::string& msg) const;

    void printInt(const int& i) const;
    void printInt(const std::string& msg) const;

    void printFloat(const float& f) const;
    void printFloat(const std::string& msg) const;

    void printDouble(const double& d) const;
    void printDouble(const std::string& msg) const;

    const char& getChar(void) const;
    const int& getInt(void) const;
    const float& getFloat(void) const;
    const double& getDouble(void) const;
    const typeSpecifier& getType(void) const;
};

#endif
