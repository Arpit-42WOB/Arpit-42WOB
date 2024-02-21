#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap constructor" << std::endl;
    _name = name;
    setEnergyPoints(ScavTrap::getEnergyPoints());
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
    std::cout << "DiamondTrap copy constructor" << std::endl;
    *this = diamondTrap;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::setName(std::string name)
{
    _name = name;
}

std::string DiamondTrap::getName() const
{
    return _name;
}
