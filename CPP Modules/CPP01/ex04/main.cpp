/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:16:35 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/28 16:15:13 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceString.hpp"

int main(int argc, char **argv)
{
	ReplaceString rs;
	
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	rs.openFile(std::string(argv[1]));
	rs.replaceString(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));
	rs.closeFile();
	return (0);
}
