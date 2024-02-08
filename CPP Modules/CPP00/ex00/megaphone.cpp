/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:27:01 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/07 18:20:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main (int argc, char **argv)
{
	char *str;

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (int j = 0; str[j] != '\0'; j++)
			{
				str[j] = std::toupper(str[j]);
				std::cout << str[j];
			}
			if (i != argc - 1)
				std::cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
