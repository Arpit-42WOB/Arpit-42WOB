#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    _type = "AAnimal";
    std::cout << "Default AAnimal Constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &Aanimal)
{
    _type = Aanimal._type;
    std::cout << "AAnimal " << _type << " is copied" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &Aanimal)
{
    this->_type = Aanimal._type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal " << this->_type << " destructed" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->_type;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal sound" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "AAnimal " << type << " is constructed" << std::endl;
}
