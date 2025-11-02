#pragma once
#include <cstdint>
#include <iostream>

template <typename T, typename Func>

void iter(T *array, const size_t len, Func function)
{
    for (size_t i = 0; i < len; i++) {
        function(array[i]);
    }
}

template <typename T>
void print(const T &element) {
    std::cout << element << std::endl;
}

template <typename T>
void increment(T& element) {
    element++;
    std::cout << element << std::endl;
}