#include "span.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <limits>

const char* Span::kErrFullMsg = "Element is full";
const char* Span::kErrLessMsg = "Less than two elements";

// exception
Span::ElementFullException::ElementFullException(const char* msg) : msg(msg) {}
const char* Span::ElementFullException::what() const throw() { return msg; }

Span::LessThanTwoException::LessThanTwoException(const char* msg) : msg(msg) {}
const char* Span::LessThanTwoException::what() const throw() { return msg; }

Span::Span(void) : maxSize_(0) {}

Span::Span(const unsigned int& N) : maxSize_(N) {}

Span::Span(const Span& other) { *this = other; }

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        maxSize_ = other.getSize();
        vec_     = other.getVec();
    }
    return *this;
}

Span::~Span(void) {}

void Span::addNumber(int n)
{
    if (vec_.size() == maxSize_)
        throw ElementFullException(kErrFullMsg);
    vec_.push_back(n);
}

unsigned int Span::shortestSpan(void)
{
    if (vec_.size() < 2)
        throw LessThanTwoException(kErrLessMsg);

    std::vector<int> tmp = vec_;
    std::sort(tmp.begin(), tmp.end());

    size_t sz             = tmp.size();
    unsigned int shortest = std::numeric_limits<unsigned int>::max();
    for (unsigned int i = 0; i < sz - 1; ++i)
    {
        unsigned int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest) shortest = diff;
    }
    return shortest;
}

unsigned int Span::longestSpan(void)
{
    if (vec_.size() < 2)
        throw LessThanTwoException(kErrLessMsg);

    std::vector<int> tmp = vec_;

    std::sort(tmp.begin(), tmp.end());
    unsigned int longest = tmp[tmp.size() - 1] - tmp[0];
    return longest;
}

// debug
void Span::Print(void) const
{
    size_t sz = vec_.size();
    std::cout << "MaxSize  : " << maxSize_ << std::endl;
    std::cout << "Elem     : ";
    for (size_t i = 0; i < sz; ++i)
    {
        std::cout << vec_[i] << " ";
    }
    std::cout << std::endl;
}

const unsigned int& Span::getSize(void) const { return maxSize_; }
const std::vector<int>& Span::getVec(void) const { return vec_; }
