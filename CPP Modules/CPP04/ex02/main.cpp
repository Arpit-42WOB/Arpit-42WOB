#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    AAnimal *CatsAndDogs[10];
    
    for (int i = 0; i < 5; i++)
        CatsAndDogs[i] = new Dog();
    for (int i = 5; i < 10; i++)
        CatsAndDogs[i] = new Cat();
    std::cout << std::endl;
    Cat copyCat(*(Cat *)CatsAndDogs[0]);
    std::cout << std::endl;

    for (int i = 0; i < 5; i++)
        std::cout << "Type: " << copyCat.getBrain()->getIdea(i) << std::endl;

    std::cout << std::endl;
    Dog copyDog(*(Dog *)CatsAndDogs[5]);
    std::cout << std::endl;

    for (int i = 5; i < 10; i++)
        std::cout << "Type: " << copyDog.getBrain()->getIdea(i) << std::endl;

    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
        delete CatsAndDogs[i];
    return 0;
}
