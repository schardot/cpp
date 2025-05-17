#include "../include/Brain.hpp"

Brain::Brain() {
    std::cout << "Default Brain constructed!" << std::endl;
}

Brain::Brain(const Brain &obj) {
    for (int i = 0; i < 100; i++) {
        ideas[i] = obj.ideas[i];
    }
    std::cout << "Brain copied!" << std::endl;
}

Brain &Brain::operator=(const Brain &obj) {
    if (this != &obj) {
        for (int i = 0; i < 100; i ++) {
            ideas[i] = obj.ideas[i];
        }
        std::cout << "Brain copied using copy assignment!" << std::endl;
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called!" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
        return "";
    return ideas[index];
}

// Mutator to set idea at index
void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
        return;
    ideas[index] = idea;
}