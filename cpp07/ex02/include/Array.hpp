#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* array_;
    unsigned int size_;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &obj);
    Array &operator=(const Array &obj);
    ~Array();
    T &operator[](unsigned int n);
    const T &operator[](unsigned int n) const;

    unsigned int size() const;
    T& getElement(unsigned int n) const;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &obj);

#include "Array.tpp"