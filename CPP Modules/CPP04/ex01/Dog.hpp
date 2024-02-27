#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;
public:
    Dog();
    Dog(std::string type);
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);
    ~Dog();
    void makeSound() const;
    Brain *getBrain() const;
};

#endif