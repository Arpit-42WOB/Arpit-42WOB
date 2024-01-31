/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:21:01 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/25 20:43:29 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	zombie("Boo");
	Zombie  *zombieHorde;
	
	zombieHorde = zombie.zombieHorde(10, "Foo");
	delete [] zombieHorde;
	zombieHorde = zombie.zombieHorde(10, "Doo");
	delete [] zombieHorde;
	return (0);
}
