#ifndef TESTER_HPP
#define TESTER_HPP

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

void pass();
void fail();

void testAddNumberBasic();

void testAddNumberOverflow();

void testRangeInsertBasic();

void testRangeInsertOverflow();

void testShortestSpanBasic();

void testShortestSpanEdge();

void testShortestSpanBug();

void testLongestSpanBasic();

void testNotEnoughElements();

void testLongestSpanConst();

void testShortestSpanConst();

#endif
