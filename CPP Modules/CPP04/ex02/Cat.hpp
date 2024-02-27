#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain *_brain;
public:
    Cat();
    Cat(std::string type);
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);
    ~Cat();
    virtual void makeSound() const;
    Brain *getBrain() const;
};

#endif