#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
public:
    Data(void);
    Data(const std::string& name, const int& value);
    Data(const Data &other);
    Data &operator=(const Data &other);
    ~Data(void);

    void Print(void) const;

    // getter
    const std::string& getName(void) const;
    const int& getValue(void) const;

    // setter
    void setName(const std::string& name);
    void setValue(const int& value);
private:
    std::string name_;
    int value_;
};

#endif
