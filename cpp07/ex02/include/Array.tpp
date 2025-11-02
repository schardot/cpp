#pragma once

template <typename T>
Array<T>::Array() : array_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]), size_(n) {}

template <typename T>
Array<T>::Array(const Array &obj) : array_(new T[obj.size()]), size_(obj.size_) {
    for (unsigned int i = 0; i < obj.size() - 1; i++)
        array_[i] = obj.array_[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &obj) {
    if (this != &obj) {
        delete[] array_;
        array_ = new T[size_];
        for (unsigned int i = 0; i < obj.size() - 1; i++)
            array_[i] = obj.array_[i];
        size_ = obj.size_;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() { delete[] array_; }

template <typename T>
T& Array<T>::operator[](unsigned int n) {
    if (n >= size_)
        throw std::out_of_range("Index out of range");
    return (array_[n]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int n) const
{
    if (n >= size_)
        throw std::out_of_range("Index out of range");
    return (array_[n]);
}

template <typename T>
unsigned int Array<T>::size() const { return size_; }

template <typename T>
T &Array<T>::getElement(unsigned int n) const {
    return array_[n];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &obj) {
    std::cout << "{";
    for (unsigned int i = 0; i < obj.size(); i ++) {
        std::cout << obj.getElement(i);
        if (i < obj.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}, size: " << obj.size() << std::endl;
    return os;
}