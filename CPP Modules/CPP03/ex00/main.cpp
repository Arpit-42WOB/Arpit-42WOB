/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:28:18 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 16:34:43 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"

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
