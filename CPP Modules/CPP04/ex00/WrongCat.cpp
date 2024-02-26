#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
    std::cout << "WrongCat " << type << " constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
    WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Woof - Woof" << std::endl;
}
