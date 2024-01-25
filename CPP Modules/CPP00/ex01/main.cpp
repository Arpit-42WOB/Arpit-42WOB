/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:28:59 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/24 13:44:12 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Header.hpp"

int main (int argc, char **argv)
{
	std::string input;
	PhoneBook	phone;

	(void)argc;
	(void)argv;
	std::cout << "PhoneBook\n" << std::endl;
	while (true)
	{
		std::cout << "Commands: ADD | SEARCH | EXIT\n" << std::endl;
		std::cout << "Enter a valid command: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "Enter getline\n";
			exit(1);
		}
		if (input == "EXIT")
		{
			std::cout << "Exiting PhoneBook" << std::endl;
			break;
		}
		if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
			phone.search();
		else
			std::cout << "Error: " << input << "is ans invalid cmd, try again\n" << std::endl;
	}
	return (0);
}
