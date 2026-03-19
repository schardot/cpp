#pragma once

#include <ostream>
#include <vector>

class Span {
	private:
		unsigned int N;
		std::vector<int> arr;

	public:

		Span() {};
		Span(unsigned int n): N(n) {};
		Span(const Span &other) : N(other.N), arr(other.arr) {}
		Span &operator=(const Span &other);

		void addNumber(int num);

		int shortestSpan() const;

		int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end) {
			size_t distance = std::distance(begin, end);

			if (arr.size() + distance > N)
				throw std::length_error("not enough space");
			arr.insert(arr.end(), begin, end);
		}

		inline const std::vector<int> &getArr() const { return arr; }
};

std::ostream &operator<<(std::ostream &os, const Span &s);
