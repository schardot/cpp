#pragma once

#include <exception>
#include <string>

class GradeTooLowException : public std::exception
{
public:
    GradeTooLowException() {};
    const char *what() const _NOEXCEPT { return "Grade too low! Lowest grade possible is 150."; }
};
