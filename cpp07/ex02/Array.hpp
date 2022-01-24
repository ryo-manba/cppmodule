#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
public:
    Array(void);
    Array(const unsigned int& n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    T& operator[](long idx);
    ~Array(void);
    const unsigned int& size(void) const;

private:
    T *array;
    unsigned int n;
};

template<typename T>
Array<T>::Array(void) : n(0)
{
    array = new T[0];
}

template<typename T>
Array<T>::Array(const unsigned int& n) : n(n)
{
    array = new T[n];
}

template<typename T>
Array<T>::Array(const Array& other)
{
    n = other.n;
    array = new T[n];
    for (unsigned int i = 0; i < n; ++i)
    {
        array[i] = other.array[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] array;
        n = other.n;
        array = new T[n];
        for (unsigned int i = 0; i < n; ++i)
        {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](long idx)
{
    if (idx < 0 || n <= idx)
        throw std::out_of_range("Array index out of range");
    return array[idx];
}

template<typename T>
Array<T>::~Array(void)
{
    delete[] array;
}

template<typename T>
const unsigned int& Array<T>::size(void) const
{
    return n;
}

#endif
