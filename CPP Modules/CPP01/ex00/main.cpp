/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:00:45 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/25 19:52:46 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie zombie("Foo");
	Zombie *zombies[10];
	
	zombie.randomChump("Bar");
	zombie.randomChump("Boo");
	zombie.randomChump("Car");
	zombie.randomChump("Doo");
	zombies[0] = zombie.newZombie("Eoo");
	zombies[1] = zombie.newZombie("Goo");
	zombies[2] = zombie.newZombie("Hoo");
	zombies[3] = zombie.newZombie("Ioo");
	zombies[4] = zombie.newZombie("Joo");

	for (int i = 0; i < 5; i++)
		delete zombies[i];
	return (0);
}
