#ifndef TESTER_HPP
#define TESTER_HPP

#include "easyfind.hpp"
#include <iostream>
#include <string>

struct IntBox {
	int value;
};

inline bool operator==(int lhs, const IntBox &rhs) {
	return lhs == rhs.value;
}

inline bool operator==(const IntBox &lhs, int rhs) {
	return lhs.value == rhs;
}

inline std::ostream &operator<<(std::ostream &os, const IntBox &box) {
	os << box.value;
	return os;
}

void printHeader(const std::string &name);
void printResult(bool pass);

// Case 1: we EXPECT to find a value
template <typename Container>
void testExpectFound(const std::string &name, Container &container, int target) {
	printHeader(name);
	std::cout << "Expect: FOUND " << target << std::endl;

	try {
		typename Container::value_type found = *easyfind(container, target);
		std::cout << "Got value: " << found << std::endl;
		printResult(found == target);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		printResult(false);
	}
}

// Case 2: we EXPECT an exception
template <typename Container>
void testExpectNotFound(const std::string &name, Container &container, int target) {
	printHeader(name);
	std::cout << "Expect: EXCEPTION for " << target << std::endl;

	try {
		std::cout << "Unexpected value: " << *easyfind(container, target) << std::endl;
		printResult(false);
	} catch (const std::exception &e) {
		std::cout  << e.what() << std::endl;
		printResult(true);
	}
}

#endif
