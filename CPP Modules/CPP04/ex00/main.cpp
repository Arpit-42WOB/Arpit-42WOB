#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp" 
#include <iostream>

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongJ = new WrongCat();
    const WrongAnimal *wrongI = new WrongCat();

    std::cout << std::endl;
    std::cout << "Animal:" << std::endl;
    std::cout << "Type: " << meta->getType() << std::endl;
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "Dog:" << std::endl;
    std::cout << "Type: " << j->getType() << std::endl;
    j->makeSound();
    std::cout << std::endl;
    std::cout << "Cat:" << std::endl;
    std::cout << "Type: " << i->getType() << std::endl;
    i->makeSound();
    std::cout << std::endl;
    std::cout << "WrongAnimal:" << std::endl;
    std::cout << "Type: " << wrongMeta->getType() << std::endl;
    wrongMeta->makeSound();
    std::cout << std::endl;
    std::cout << "WrongCat:" << std::endl;
    std::cout << "Type: " << wrongJ->getType() << std::endl;
    wrongJ->makeSound();
    std::cout << std::endl;
    std::cout << "WrongCat:" << std::endl;
    std::cout << "Type: " << wrongI->getType() << std::endl;
    wrongI->makeSound();
    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongJ;
    delete wrongI;
    return 0;
}