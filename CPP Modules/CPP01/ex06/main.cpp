/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:25:21 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/07 18:43:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl	command;
	std::string input;

	do
	{
		std::cout << "Enter a level: ";
		std::cin >> input;
		command.complain(input);
	} while (input != "EXIT");
	
	return (0);
}