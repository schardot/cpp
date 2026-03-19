#include "../include/tester.hpp"
#include <deque>
#include <list>
#include <vector>

int main() {
	int vArr[] = {1, 2, 3, 4};
	std::vector<int> v(vArr, vArr + 4);

	int lArr[] = {10, 20, 30};
	std::list<int> l(lArr, lArr + 3);

	int dArr[] = {8, 9, 10, 11};
	std::deque<int> d(dArr, dArr + 4);

	std::vector<int> empty;

	testExpectFound("Vector - Found", v, 3);
	testExpectNotFound("Vector - Not Found", v, 9);

	testExpectFound("List - Found", l, 20);
	testExpectNotFound("List - Not Found", l, 99);

	testExpectFound("Deque - Found", d, 10);
	testExpectNotFound("Deque - Not Found", d, 0);

	testExpectNotFound("Empty Vector", empty, 1);

	testExpectFound("First Element", v, 1);
	testExpectFound("Last Element", v, 4);

	int dupArr[] = {1, 2, 2, 3};
	std::vector<int> dup(dupArr, dupArr + 4);
	testExpectFound("Duplicates", dup, 2);

	IntBox customBoxes[] = {{1}, {5}, {10}};
	std::vector<IntBox> customVec(customBoxes, customBoxes + 3);
	testExpectFound("IntBox Vector - Found", customVec, 5);
	testExpectNotFound("IntBox Vector - Not Found", customVec, 7);

	// Const container tests
	const int cvArr[] = {1, 2, 3, 4};
	const std::vector<int> constVec(cvArr, cvArr + 4);

	const int cdArr[] = {8, 9, 10, 11};
	const std::deque<int> constDeque(cdArr, cdArr + 4);

	IntBox ccBoxes[] = {{1}, {5}, {10}};
	const std::vector<IntBox> constCustomVec(ccBoxes, ccBoxes + 3);

	testExpectFound("Const Vector - Found", constVec, 3);
	testExpectNotFound("Const Vector - Not Found", constVec, 9);

	testExpectFound("Const Deque - Found", constDeque, 10);
	testExpectNotFound("Const Deque - Not Found", constDeque, 0);

	testExpectFound("Const IntBox Vector - Found", constCustomVec, 5);
	testExpectNotFound("Const IntBox Vector - Not Found", constCustomVec, 7);

	return 0;
}
