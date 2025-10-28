#pragma once

template <typename T>
void swap(T &a, T &b) {

    T c = a;
    a = b;
    b = c;
};

template <typename T>
T const &min(T const &a, T const &b) {
    if (a < b)
        return a;
    return b;
};

template <typename T>
T const &max(T const &a, T const &b) {
    if (a > b)
        return a;
    return b;
};