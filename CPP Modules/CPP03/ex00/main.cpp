#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap first("First Trap");
	first.setAttackDamage(3);
	first.setEnergyPoints(4);
	std::cout << "First Trap has " << first.getAttackDamage() << " attack damage and " << first.getEnergyPoints() << " energy points" << std::endl;
	
	ClapTrap second("Second Trap");
	std::cout << "Second Trap has " << second.getAttackDamage() << " attack damage and " << second.getEnergyPoints() << " energy points" << std::endl;
	
	first.attack(second.getName());
	second.takeDamage(first.getAttackDamage());
	std::cout <<std::endl;

	second.beRepaired(1);
	std::cout <<std::endl;

	second.attack(first.getName());
	first.takeDamage(second.getAttackDamage());
	std::cout <<std::endl;

	first.attack(second.getName());
	second.takeDamage(first.getAttackDamage());
	std::cout <<std::endl;

	first.attack(second.getName());
	second.takeDamage(first.getAttackDamage());
	std::cout <<std::endl;

	first.attack(second.getName());
	second.takeDamage(first.getAttackDamage());
	std::cout <<std::endl;

	first.attack(second.getName());
	second.takeDamage(first.getAttackDamage());
	std::cout <<std::endl;

	return (0);
}
