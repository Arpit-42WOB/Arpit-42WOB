#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : AAnimal(cat)
{
    this->_brain = new Brain(*cat._brain);
    std::cout << "Cat "<< cat._type << " constructor copied" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type), _brain(new Brain())
{
    std::cout << "Cat " << type << " is Constructed" << std::endl;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat " << this->_type << " is Destructed" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    this->_brain = new Brain(*cat._brain);
    this->_type = cat._type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow - Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->_brain;
}
