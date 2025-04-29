#include <iostream>

int main (void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of string var: " << &str << std::endl
				<< "Address held by stringPTR: " << stringPTR << std::endl
				<< "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of string var: " << str << std::endl
	<< "Value pointed to by stringPTR: " << *stringPTR << std::endl
	<< "Value pointed to by stringREF: " << stringREF << std::endl;

}
