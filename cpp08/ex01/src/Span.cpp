#include "Span.hpp"
#include <iostream>

Span::Span() {}

Span::Span(unsigned int n) : n_(n) {}

Span::Span(const Span &obj) : v_(obj.v_), n_(obj.n_) {}

const Span &Span::operator=(const Span &obj) {
    if (this != &obj) {
        this->v_ = obj.v_;
        this->n_ = obj.n_;
    }
    return *this;
}

const std::vector<int> Span::getNumbers() { return (v_); }

void Span::addNumber(int x) {
    if (v_.size() == n_)
        throw std::runtime_error("Reached maximum capacity");
    v_.push_back(x);
}

int Span::shortestSpan() {
    if (v_.size() < 2)
        throw std::runtime_error("Need at least 2 elements to calculate span");

    std::vector<int> sorted = v_;
    std::sort(sorted.begin(), sorted.end());

    unsigned int span = UINT_MAX;
    for (std::vector<int>::iterator it = sorted.begin(); it + 1 != sorted.end(); ++it)
    {
        int diff = *(it + 1) - *it;
        if (static_cast<unsigned int> (diff) < span)
            span = diff;
    }
    return span;
}

int Span::longestSpan() {
    if (v_.size() < 2)
        throw std::runtime_error("Need at least 2 elements to calculate span");

        int min = *std::min_element(v_.begin(), v_.end());
        int max = *std::max_element(v_.begin(), v_.end());
    return max - min;
};

std::ostream &operator<<(std::ostream &os, Span &obj) {
    std::vector<int> nbs = obj.getNumbers();
    for (size_t i = 0; i < nbs.size(); ++i) {
        os << nbs[i];
        if (i == nbs.size() - 1)
            break;
        os << " ";
    }
    os << std::endl;
    return os;
}
