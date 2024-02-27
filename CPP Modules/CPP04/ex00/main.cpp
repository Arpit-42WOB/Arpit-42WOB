#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *Sheru = new Dog("Sheru");
    const Animal *Lily = new Cat("Lily");
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *Bella = new WrongCat("Bella");

    std::cout << std::endl;
    std::cout << "Animal:" << std::endl;
    std::cout << "Type: " << meta->getType() << std::endl;
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "Dog:" << std::endl;
    std::cout << "Type: " << Sheru->getType() << std::endl;
    Sheru->makeSound();
    std::cout << std::endl;
    std::cout << "Cat:" << std::endl;
    std::cout << "Type: " << Lily->getType() << std::endl;
    Lily->makeSound();
    std::cout << std::endl;
    std::cout << "WrongAnimal:" << std::endl;
    std::cout << "Type: " << wrongMeta->getType() << std::endl;
    wrongMeta->makeSound();
    std::cout << std::endl;
    std::cout << "WrongCat:" << std::endl;
    std::cout << "Type: " << Bella->getType() << std::endl;
    Bella->makeSound();
    std::cout << std::endl;

    delete meta;
    delete Sheru;
    delete Lily;
    delete wrongMeta;
    delete Bella;
    return 0;
}
