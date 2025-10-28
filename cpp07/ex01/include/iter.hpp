#pragma once
#include <cstdint>

template <typename T, typename Func>

void iter(T *array, const int len, Func function) {
    for (int i = 0; i < len; i++) {
        function(array[i]);
    }
}