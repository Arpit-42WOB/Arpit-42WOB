#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	ClapTrap();
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &obj);
	ClapTrap &operator=(ClapTrap const &obj);
	~ClapTrap();
	void attack(std::string const & target);
	void takeDamage(int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	
	void setHitPoints(int hitpoints);
	void setEnergyPoints(int energy_points);
	void setAttackDamage(int attack_damage);
};

#endif
