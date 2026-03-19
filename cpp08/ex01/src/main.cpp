#include "../include/tester.hpp"
#include "../include/Span.hpp"

int main() {
	// testAddNumberBasic();
	// testAddNumberOverflow();

	// testRangeInsertBasic();
	// testRangeInsertOverflow();

	// testShortestSpanBasic();
	// testShortestSpanEdge();
	// testShortestSpanBug();

	// testLongestSpanBasic();

	// testNotEnoughElements();

	// testLongestSpanConst();

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}