#include "Brain.hpp"

Brain::Brain() {
    const std::string list[] = { "Idea 1", "Idea 2", "Idea 3", "Idea 4", "Idea 5" };
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = list[rand() % 5];
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &other) {
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructed" << std::endl;
}

Brain &Brain::operator=(Brain const &other) {
    if (this != &other)
    {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

const std::string& Brain::getIdea(int index) const {
    return this->_ideas[index];
}
