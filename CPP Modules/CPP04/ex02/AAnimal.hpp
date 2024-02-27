#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
    std::string _type;

public:
    AAnimal();
    AAnimal(std::string type);
    virtual ~AAnimal();
    AAnimal(const AAnimal &Aanimal);
    AAnimal &operator=(const AAnimal &Aanimal);
    std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif