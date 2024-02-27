#ifndef BRIAN_HPP
# define BRIAN_HPP

# include <string>
# include <iostream>
# include <cstdlib>
class Brain {
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(Brain const &other);
        Brain &operator=(Brain const &other);
        const std::string &getIdea(int index) const;
};

#endif
