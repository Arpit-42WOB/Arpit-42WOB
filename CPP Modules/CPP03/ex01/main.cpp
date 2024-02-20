#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap	Foo( "Foo" );
	std::cout << Foo.getName() << "'s stats" << std::endl;
	std::cout << "Hitpoints: " << Foo.getHitPoints() << std::endl;
	std::cout << "Energy points: " << Foo.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << Foo.getAttackDamage() << std::endl;
	std::cout << std::endl;

	ClapTrap	Boo( "Boo" );
	Boo.setAttackDamage( 42 );
	std::cout << Boo.getName() << "'s stats" << std::endl;
	std::cout << "Hitpoints: " << Boo.getHitPoints() << std::endl;
	std::cout << "Energy points: " << Boo.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << Boo.getAttackDamage() << std::endl;
	std::cout << std::endl;

	Foo.attack( Boo.getName() );
	Boo.takeDamage( Foo.getAttackDamage() );
	std::cout << std::endl;

	Boo.attack( Foo.getName() );
	Boo.beRepaired( 2 );
	Boo.attack( Foo.getName() );
	Foo.takeDamage( Boo.getAttackDamage() );
	Foo.beRepaired( 3 );
	Foo.guardGate();
	std::cout << std::endl;

	return 0;
}