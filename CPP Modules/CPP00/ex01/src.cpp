/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:47:41 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/23 21:24:29 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

std::string get_check_input (std::string str)
{
	std::string input;
	do
	{
		std::cout << str;
		if (!std::getline(std::cin, input))
		{
			std::cout << "Error getline\n";
			exit(1);
		}
	}	while (input.empty());
	return (input);
}

bool	is_number(std::string str)
{
	size_t	i;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

std::string starting_form(std::string str)
{
	std::string format;
	if (str.length() <= 9)
		return (str);
	else
	{
		format = str.substr(0, 9).append(".");
		return (format);
	}
}
