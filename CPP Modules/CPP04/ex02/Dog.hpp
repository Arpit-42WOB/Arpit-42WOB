#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *_brain;
public:
    Dog();
    Dog(std::string type);
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);
    ~Dog();
    virtual void makeSound() const;
    Brain *getBrain() const;
};

#endif