#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <exception>
#include <string>
#include <vector>

class Span
{
public:
    Span(const unsigned int& N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span(void);

    void addNumber(int n);

    template <class InputIte>
    void addNumber(InputIte begin, InputIte end)
    {
        for (; begin != end; ++begin)
        {
            if (vec_.size() == maxSize_)
                throw ElementFullException(kErrFullMsg);
            vec_.push_back(*begin);
        }
    }

    unsigned int shortestSpan(void) const;
    unsigned int longestSpan(void) const;

    const unsigned int& getSize(void) const;
    const std::vector<int>& getVec(void) const;

    void Print(void) const;

private:
    const static char* kErrFullMsg;
    const static char* kErrLessMsg;
    Span(void);

    unsigned int maxSize_;
    std::vector<int> vec_;

    class ElementFullException : public std::exception
    {
    public:
        ElementFullException(const char* msg);
        const char* what() const throw();

    private:
        const char* msg;
    };
    class LessThanTwoException : public std::exception
    {
    public:
        LessThanTwoException(const char* msg);
        const char* what() const throw();

    private:
        const char* msg;
    };
};
#endif
