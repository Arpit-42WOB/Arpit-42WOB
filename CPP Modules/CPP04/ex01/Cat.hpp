#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;
public:
    Cat();
    Cat(std::string type);
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);
    ~Cat();
    void makeSound() const;
    Brain *getBrain() const;
};

#endif