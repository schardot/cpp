#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public AAnimal
{
private:
    Brain *catBrain;
public:
    Cat();
    Cat(const Cat &obj);
    Cat &operator=(const Cat &obj);
    ~Cat();

    virtual void makeSound() const;
    Brain *getBrain() const;
};

#endif