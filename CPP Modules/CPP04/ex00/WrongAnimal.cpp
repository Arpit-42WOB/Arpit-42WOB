#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "Default WrongAnimal Constructed" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << "WrongAnimal "<< type <<" is Constructed" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
    *this = other;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal "<< this->_type << " destructed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
    this->_type = other._type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}
