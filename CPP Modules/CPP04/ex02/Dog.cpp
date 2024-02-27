#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
    std::cout << "Defauls Dog constructor called" << std::endl;
}

Dog::Dog(std::string type) : AAnimal(type), _brain(new Brain()) {
    std::cout << "Dog " << type << " is Constructed" << std::endl;
}

Dog::Dog(Dog const &other) : AAnimal(other) {
    this->_brain = new Brain(*other._brain);
    std::cout << "Dog " << other._type << " Constructor Copied" << std::endl;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog " << this->_type << " is Destructed" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
    this->_brain = new Brain(*other._brain);
    this->_type = other._type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof - Woof" << std::endl;
}

Brain *Dog::getBrain() const {
    return this->_brain;
}
