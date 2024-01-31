/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:32:15 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/28 17:23:58 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
	void (Harl::*_memfunc[4])(void);
	std::string _level[4];
	
	void debug();
	void info();
	void warning();
	void error();
public:
	Harl();
	~Harl();

	void complain(std::string level);
};

#endif