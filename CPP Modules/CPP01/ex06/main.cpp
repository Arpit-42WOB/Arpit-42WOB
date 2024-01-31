/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:25:21 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/29 11:50:06 by amehrotr         ###   ########.fr       */
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
	} while (input.compare("EXIT"));
	
	return (0);
}
