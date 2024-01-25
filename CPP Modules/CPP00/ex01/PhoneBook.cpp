/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:20 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/24 13:51:04 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this ->_size = 0;
}

void PhoneBook::add()
{
	std::cout << "\nAdd - New Contact:" << std::endl;
	this->_contacts[this->_index].set_full_info();
	std::cout << "Success!!" << std::endl;
	this->_index++;
	this->_size++;
	if (this->_index == 8)
		this->_index = 0;
}

void PhoneBook::search()
{
	int num;
	std::string input;

	if (this->_size == 0)
	{
		std::cout << "\nNo Contact to Display\n" << std::endl;
		return;
	}
	while (true)
	{
		this->search_display(10);
		std::cout << "\nPlease enter index of the contact: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "Error on getline" << std::endl;
			break;
		}
		if (input == "EXIT")
			break;
		if (input.empty() || !is_number(input))
		{
			std::cout << std::endl << input << "invalid input, Try again" << std::endl;
			continue;
		}
		num = std::atoi(input.c_str());
		if (num < 0 || num >= this->_size || num > 7)
			std::cout << "\nError: Index out of range, Try again\n" << std::endl;
		else
			this->get_contact(num).get_full_info();
	}
}

void PhoneBook::search_display(int spc)
{
	int		i;
	
	std::cout << std::setw(spc) << "Index" << "|";
	std::cout << std::setw(spc) << "First Name" << "|";
	std::cout << std::setw(spc) << "Last Name" << "|";
	std::cout << std::setw(spc) << "Nick Name" << "|";
	std::cout << std::endl;
	for (i = 0; (i < this->_size && i < 8); i++)
	{
		std::cout << std::setw(spc) << i << "|"; 
		std::cout << std::setw(spc) << starting_form(get_contact(i).get_first_name()) << "|";
		std::cout << std::setw(spc) << starting_form(get_contact(i).get_last_name()) << "|";
		std::cout << std::setw(spc) << starting_form(get_contact(i).get_nick_name()) << "|";
		std::cout << std::endl;
	}
}

Contact PhoneBook::get_contact(int index)
{
	return (this->_contacts[index]);
}
