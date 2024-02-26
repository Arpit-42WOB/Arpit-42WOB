#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    std::cout << "Cat "<< cat._type << " constructor copied" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat " << type << " constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat " << this->_type << "destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    this->_type = cat._type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow - Meow" << std::endl;
}
