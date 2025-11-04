#include "RPN.hpp"
#include <iostream>
#include <exception>


RPN::RPN() {}

RPN::RPN(const std::string &arg) {
    try {
        execute(arg);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

RPN::RPN(const RPN &obj) { (void) obj; }

RPN &RPN::operator=(const RPN &obj) {
    (void) obj;
    return *this;
}

RPN::~RPN() {}

void RPN::execute(std::string arg) {
    while (!arg.empty()) {
        if (std::isdigit(arg.front()))
            nums.push(arg.front() - 48);
        else if (arg.front() == ' ')
            ;
        else
            performOperation(arg.front());
        arg.erase(arg.begin());
    }
    if (nums.size() != 1)
        throw std::runtime_error("Error: invalid operation");
    std::cout << nums.top() << std::endl;
};

void RPN::performOperation(char op) {

    if (nums.empty() || nums.size() < 2)
        throw std::runtime_error("Error: invalid operation");

    int num = nums.top();
    nums.pop();
    int num2 = nums.top();
    nums.pop();

    int result = 0;
    switch (op) {
        case '+':
            result = (num + num2);
            break;
        case '-':
            result = (num2 - num);
            break;
        case '*':
            result = (num * num2);
            break;
        case '/':
            result = (num2 / num);
            break;
        default:
            throw std::runtime_error("Not a valid operation");
    }
    nums.push(result);
}