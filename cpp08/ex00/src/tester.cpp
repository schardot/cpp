#include "tester.hpp"

void printHeader(const std::string &name) {
	std::cout << "\n=== " << name << " ===" << std::endl;
}

void printResult(bool pass) {
	std::cout << (pass ? "[PASS]" : "[FAIL]") << std::endl;
}
