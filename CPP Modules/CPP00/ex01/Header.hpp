/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:37:05 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/23 20:38:38 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

std::string		get_check_input(std::string input);
std::string		starting_form (std::string str);
bool			is_number(std::string str);

#endif