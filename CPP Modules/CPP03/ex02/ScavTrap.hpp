#ifndef SCARVTRAP_HPP
# define SCARVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &copy);
	void guardGate();
	void attack(const std::string &target);
};

#endif