#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Defauls Dog constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    std::cout << "Dog " << type << " constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) {
    std::cout << "Dog " << other._type << " constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog " << this->_type << " destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
    Animal::operator=(other);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof - Woof" << std::endl;
}
