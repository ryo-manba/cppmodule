#include "Fixed.hpp"

#include <iostream>
#include <cmath>

const int Fixed::point_ = 8;

Fixed::Fixed() : fpv_(0) {}

Fixed::Fixed(const int &value)
{
    this->fpv_ = value << this->point_;
}

Fixed::Fixed(const float &value)
{
    this->fpv_ = static_cast<int>(std::roundf(value * (1 << this->point_)));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        fpv_ = other.fpv_;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->fpv_;
}

void Fixed::setRawBits(int const raw)
{
    this->fpv_ = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->fpv_) / (1 << this->point_);
}

int Fixed::toInt(void) const
{
    return this->fpv_ / (1 << this->point_);
}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs)
{
    lhs << rhs.toFloat();
    return lhs;
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return this->fpv_ > rhs.fpv_;
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return this->fpv_ < rhs.fpv_;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return !(this->fpv_ < rhs.fpv_);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return !(this->fpv_ > rhs.fpv_);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return this->fpv_ == rhs.fpv_;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return !(*this == rhs);
}

const Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed res;

    res.setRawBits(this->fpv_ + rhs.fpv_);
    return res;
}

const Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed res;

    res.setRawBits(this->fpv_ - rhs.fpv_);
    return res;
}

const Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed res;
    long tmp = this->fpv_;

    tmp *= rhs.fpv_;
    tmp >>= point_;
    res.setRawBits(static_cast<int>(tmp));
    return res;
}

const Fixed Fixed::operator/(const Fixed &rhs) const
{
    if (rhs.fpv_ == 0)
    {
        std::cout << "Error : Divide by Zero" << std::endl;
        std::exit(1);
    }

    Fixed res;
    long tmp = this->fpv_;

    tmp = (tmp << this->point_) / rhs.fpv_;
    res.setRawBits(static_cast<int>(tmp));
    return res;
}

Fixed& Fixed::operator++()
{
    ++fpv_;
    return *this;
}

Fixed& Fixed::operator--()
{
    --fpv_;
    return *this;
}

const Fixed Fixed::operator++(int)
{
    const Fixed tmp(*this);

    ++(*this);
    return tmp;
}

const Fixed Fixed::operator--(int)
{
    const Fixed tmp(*this);

    --(*this);
    return tmp;
}
