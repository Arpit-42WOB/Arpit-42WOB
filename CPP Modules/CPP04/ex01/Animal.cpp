#include "Animal.hpp"

Animal::Animal()
{
    _type = "Animal";
    std::cout << "Default Animal Constructed" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    _type = animal._type;
    std::cout << "Animal " << _type << " is copied" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    this->_type = animal._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal " << this->_type << " destructed" << std::endl;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal " << type << " is constructed" << std::endl;
}
