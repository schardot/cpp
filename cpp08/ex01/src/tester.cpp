#include "../include/tester.hpp"
#include "../include/Span.hpp"

void printHeader(const std::string &name) {
	std::cout << "\n=== " << name << " ===" << std::endl;
}

void printResult(bool pass) {
	std::cout << (pass ? "[PASS]" : "[FAIL]") << std::endl;
}

void pass() { std::cout << "[PASS]" << std::endl; }
void fail() { std::cout << "[FAIL]" << std::endl; }

void testAddNumberBasic() {
	printHeader("AddNumber Basic");

	Span s(3);

	try {
		s.addNumber(1);
		s.addNumber(2);
		s.addNumber(3);
		pass();
	} catch (...) {
		fail();
	}
}

void testAddNumberOverflow() {
	printHeader("AddNumber Overflow");

	Span s(2);

	try {
		s.addNumber(1);
		s.addNumber(2);
		s.addNumber(3); // should throw
		fail();
	} catch (const std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
		pass();
	}
}

void testRangeInsertBasic() {
	printHeader("Range Insert Basic");

	Span s(10);

	int vArr[] = {1, 2, 3, 4};
	std::vector<int> v(vArr, vArr + 4);

	try {
		s.addRange(v.begin(), v.end());
		pass();
	} catch (...) {
		fail();
	}
}

void testRangeInsertOverflow() {
	printHeader("Range Insert Overflow");

	Span s(3);

	int vArr[] = {1, 2, 3, 4};
	std::vector<int> v(vArr, vArr + 4);

	try {
		s.addRange(v.begin(), v.end());
		fail();
	} catch (const std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
		pass();
	}
}

void testShortestSpanBasic() {
	printHeader("ShortestSpan Basic");

	Span s(5);
	s.addNumber(10);
	s.addNumber(3);
	s.addNumber(20);
	s.addNumber(6);

	try {
		int result = s.shortestSpan();
		std::cout << "Result: " << result << std::endl;
		pass();
	} catch (...) {
		fail();
	}
}

void testShortestSpanEdge() {
	printHeader("ShortestSpan Edge (2 elements)");

	Span s(2);
	s.addNumber(5);
	s.addNumber(100);

	try {
		int result = s.shortestSpan();
		std::cout << "Result: " << result << std::endl;
		pass();
	} catch (...) {
		fail();
	}
}

void testShortestSpanBug() {
	printHeader("ShortestSpan not sorted");

	Span s(3);
	s.addNumber(100);
	s.addNumber(1);
	s.addNumber(50);

	try {
		int result = s.shortestSpan();
		std::cout << "Result: " << result << std::endl;
		std::cout << "Expected: 49 (between 50 and 1 after sorting)" << std::endl;
		pass();
	} catch (...) {
		fail();
	}
}

void testLongestSpanBasic() {
	printHeader("LongestSpan Basic");

	Span s(5);
	s.addNumber(10);
	s.addNumber(3);
	s.addNumber(20);
	s.addNumber(6);

	try {
		int result = s.longestSpan();
		std::cout << "Result: " << result << std::endl;
		pass();
	} catch (...) {
		fail();
	}
}

void testNotEnoughElements() {
	printHeader("Not Enough Elements");

	Span s(5);
	s.addNumber(10);

	try {
		s.shortestSpan();
		fail();
	} catch (const std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
		pass();
	}

	try {
		s.longestSpan();
		fail();
	} catch (const std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
		pass();
	}
}

void testLongestSpanConst() {
	printHeader("LongestSpan with const Span");

	Span s(5);
	s.addNumber(1);
	s.addNumber(10);

	const Span &cs = s;

	try {
		int result = cs.longestSpan();
		std::cout << "Result: " << result << std::endl;
		pass();
	} catch (...) {
		fail();
	}
}

void testShortestSpanConst() {
		printHeader("LongestSpan with const Span");

		Span s(5);

		int vArr[] = {1, 20, 13, 42};
		std::vector<int> v(vArr, vArr + 4);

		s.addRange(v.begin(), v.end());
		const Span &cs = s;

		try {
		int result = cs.shortestSpan();
		std::cout << "Result: " << result << std::endl;
		pass();
		} catch (...) {
		fail();
		}
}