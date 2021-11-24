#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const int& value);
    Fixed(const float &value);
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    const Fixed operator+(const Fixed &rhs) const;
    const Fixed operator-(const Fixed &rhs) const;
    const Fixed operator*(const Fixed &rhs) const;
    const Fixed operator/(const Fixed &rhs) const;

    Fixed& operator++();
    Fixed& operator--();
    const Fixed operator++(int);
    const Fixed operator--(int);

    static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
    static Fixed &min(Fixed &lhs, Fixed &rhs);
    static const Fixed &max(const Fixed &lhs, const Fixed &rhs);
    static Fixed &max(Fixed &lhs, Fixed &rhs);
private:
    int fpv_;
    static const int point_;
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);

#endif
