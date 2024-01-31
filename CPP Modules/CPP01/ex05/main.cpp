/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:32:18 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/28 18:12:50 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
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
