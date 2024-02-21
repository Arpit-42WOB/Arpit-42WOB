#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	Foo( "Foo" );
	std::cout << Foo.getName() << "'s stats" << std::endl;
	std::cout << "Hitpoints: " << Foo.getHitPoints() << std::endl;
	std::cout << "Energy points: " << Foo.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << Foo.getAttackDamage() << std::endl;
	std::cout << std::endl;

	FragTrap	Doo( "Doo" );
	std::cout << Doo.getName() << "'s stats" << std::endl;
	std::cout << "Hitpoints: " << Doo.getHitPoints() << std::endl;
	std::cout << "Energy points: " << Doo.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << Doo.getAttackDamage() << std::endl;
	std::cout << std::endl;

	Foo.whoAmI();
	Doo.highFivesGuys();
	std::cout << std::endl;

	Foo.guardGate();
	Foo.highFivesGuys();
	std::cout << std::endl;

	Foo.attack( Doo.getName() );
	Doo.takeDamage( Foo.getAttackDamage() );
	Doo.attack( Foo.getName() );
	Foo.takeDamage( Doo.getAttackDamage() );
	std::cout << std::endl;

	Foo.attack( Doo.getName() );
	Doo.takeDamage( Foo.getAttackDamage() );
	Foo.attack( Doo.getName() );
	Doo.takeDamage( Foo.getAttackDamage() );
	Foo.attack( Doo.getName() );
	Doo.takeDamage( Foo.getAttackDamage() );
	Foo.attack( Doo.getName() );
	Doo.takeDamage( Foo.getAttackDamage() );
	std::cout << std::endl;

	return 0;
}