#include "Fixed.hpp"

#include <iostream>
#include <cmath>

const int Fixed::point_ = 8;

Fixed::Fixed() : fpv_(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fpv_ = value << this->point_;
}

Fixed::Fixed(const float &value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fpv_ = static_cast<int>(std::roundf(value * (1 << this->point_)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        fpv_ = other.fpv_;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fpv_;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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

