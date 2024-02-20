#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	
	std::cout << "ClapTrap " << _name << " assembled" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	_name= other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	
	std::cout << "ClapTrap " << _name << " duplicated" << std::endl;	
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	if (this != &other)
	{
		this->_name= other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "ClapTrap " << _name << "has copied" << std::endl;
	}
	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
		return ;
	}

	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has insufficient energy to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << 
	" causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is now dead" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hitpoints left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hitpoints now" << std::endl;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &clap)
{
	out << "Name: " << clap.getName() << " Hitpoints: " << clap.getHitPoints() << 
	" Energy: " << clap.getEnergyPoints() << " Attack: " << clap.getAttackDamage();
	return (out);
}

std::string ClapTrap::getName() const
{
	return (_name);
}

int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void ClapTrap::setHitPoints(int hitpoints)
{
	_hitPoints = hitpoints;
}

void ClapTrap::setEnergyPoints(int energy_points)
{
	_energyPoints = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage)
{
	_attackDamage = attack_damage;
}
