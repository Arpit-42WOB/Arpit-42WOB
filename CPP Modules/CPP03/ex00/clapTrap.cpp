/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:28:13 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 16:35:21 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"

ClapTrap::ClapTrap()
{
	_hitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
	
	std::cout << "ClapTrap " << _name << " assembled" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	_name= other._name;
	_hitpoints = other._hitpoints;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	
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
		this->_hitpoints = other._hitpoints;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
		std::cout << "ClapTrap " << _name << "has copied" << std::endl;
	}
	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
		return ;
	}

	if (_energy_points == 0)
	{
		std::cout << "ClapTrap " << _name << " has insufficient energy to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(int amount)
{
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (amount >= _hitpoints)
	{
		_hitpoints = 0;
		std::cout << "ClapTrap " << _name << " is now dead" << std::endl;
		return ;
	}
	_hitpoints -= amount;
	std::cout << "ClapTrap " << _name << " has " << _hitpoints << " hitpoints left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
	_hitpoints += amount;
	std::cout << "ClapTrap " << _name << " has " << _hitpoints << " hitpoints now" << std::endl;
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &clap)
{
	out << "Name: " << clap.getName() << " Hitpoints: " << clap.getHitpoints() << " Energy: " << clap.getEnergyPoints() << " Attack: " << clap.getAttackDamage();
	return (out);
}

std::string ClapTrap::getName() const
{
	return (_name);
}

int ClapTrap::getHitpoints() const
{
	return (_hitpoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (_energy_points);
}

int ClapTrap::getAttackDamage() const
{
	return (_attack_damage);
}

void ClapTrap::setHitpoints(int hitpoints)
{
	_hitpoints = hitpoints;
}

void ClapTrap::setEnergyPoints(int energy_points)
{
	_energy_points = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage)
{
	_attack_damage = attack_damage;
}
