/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:28:15 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 16:34:09 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	ClapTrap();
	std::string _name;
	int _hitpoints;
	int _energy_points;
	int _attack_damage;
public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &obj);
	ClapTrap &operator=(ClapTrap const &obj);
	~ClapTrap();
	void attack(std::string const & target);
	void takeDamage(int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	int getHitpoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	
	void setHitpoints(int hitpoints);
	void setEnergyPoints(int energy_points);
	void setAttackDamage(int attack_damage);
};

#endif
