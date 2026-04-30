#pragma once

#include <stack>
#include <string>

class RPN
{
private:
    std::stack<int> nums;

public:
    RPN(const std::string &arg);
    ~RPN();
    RPN();
    RPN(const RPN &obj);
    RPN &operator=(const RPN &obj);

    void execute(std::string arg);
    void performOperation(char op);
};

