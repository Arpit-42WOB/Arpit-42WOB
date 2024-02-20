#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << getName() << " assembled" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " destructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	ClapTrap::operator=(copy);
	std::cout << "ScavTrap assignation operator" << std::endl;
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " have enterred in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() << " is out of energy" << std::endl;
		return ;
	}
	if (getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() << " is Dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}