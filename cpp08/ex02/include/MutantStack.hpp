#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack &obj) : std::stack<T>(obj) {}
    MutantStack &operator=(const MutantStack &obj)
    {
        if (this != &obj)
            std::stack<T>::operator=(obj);
        return *this;
    }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator IT;
    IT begin() { return this->c.begin(); };
    IT end() { return this -> c.end(); };
};

