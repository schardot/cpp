#pragma once
#include <vector>
#include <iterator>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
    std::vector<int> v_;
    unsigned int n_;
public:
    Span();
    Span(unsigned int n);
    Span(const Span &obj);
    const Span &operator=(const Span &obj);
    ~Span() {};

    const std::vector<int> getNumbers();
    void addNumber(int x);
    int shortestSpan();
    int longestSpan();

    template <typename IT>
    void addRange(IT begin, IT end)
    {
        size_t distance = std::distance(begin, end);

        if (v_.size() + distance > n_)
            throw std::runtime_error("Not enough space to add all range");

        v_.insert(v_.end(), begin, end);
    }
};

std::ostream &operator<<(std::ostream &os, Span &obj);

