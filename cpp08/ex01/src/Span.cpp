#include "../include/Span.hpp"
#include <iostream>

Span & Span::operator=(const Span &other) {
	if (this != &other) {
		N = other.N;
		arr = other.arr;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (arr.size() < N) {
		arr.push_back(num);
		return;
	}
	throw std::length_error("object is full");
};

int Span::shortestSpan() const {
	if (arr.size() < 2)
		throw std::logic_error("not enough elements");

	std::vector<int> tmp = arr;
	std::sort(tmp.begin(), tmp.end());

	int minSpan = INT_MAX;

	for (size_t i = 1; i < tmp.size(); ++i)
		minSpan = std::min(minSpan, tmp[i] - tmp[i - 1]);

	return minSpan;
}

int Span::longestSpan() const {
	if (arr.size() < 2)
		throw std::logic_error("need at least 2 elements");
	return *std::max_element(arr.begin(), arr.end()) -
				*std::min_element(arr.begin(), arr.end());
}

std::ostream &operator<<(std::ostream &os, const Span &s) {
	os << "[ ";

	for (std::vector<int>::const_iterator it = s.getArr().begin();
			it != s.getArr().end(); ++it) {
		os << *it;

		std::vector<int>::const_iterator next = it;
		++next;
		if (next != s.getArr().end())
			os << ", ";
	}

	os << " ]";
	return os;
}