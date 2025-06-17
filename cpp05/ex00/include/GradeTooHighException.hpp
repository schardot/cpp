#pragma once

#include <exception>
#include <string>

class GradeTooHighException : public std::exception
{
public:
    GradeTooHighException() {};
    const char *what() const _NOEXCEPT { return "Grade too high! Highest grade possible is 1."; }
};

