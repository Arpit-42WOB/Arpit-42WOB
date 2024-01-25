/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:44:56 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/23 20:44:05 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string		Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string		Contact::get_last_name(void)
{
	return (this->_last_name);
}

std::string		Contact::get_nick_name(void)
{
	return (this->_nick_name);
}

std::string		Contact::get_phone_number(void)
{
	return (this->_phone_number);
}

std::string		Contact::get_darkest_secret(void)
{
	return (this->_darkest_secret);
}

void    Contact::get_full_info(void) {
    std::cout << "\n+++++-CONTACT-+++++" << std::endl;
    std::cout << "+ First Name: " << this->get_first_name() << std::endl;
    std::cout << "+ Last Name: " << this->get_last_name() << std::endl;
    std::cout << "+ Nickname: " << this->get_nick_name() << std::endl;
    std::cout << "+ Phone Number: " << this->get_phone_number() << std::endl;
    std::cout << "+ Darkest Secret: " << this->get_darkest_secret() << std::endl;
    std::cout << "++++++++++++++++++++\n" << std::endl;
}

void    Contact::set_full_info(void) {
    this->_first_name = get_check_input("First Name: ");
    this->_last_name = get_check_input("Last Name: ");
    this->_nick_name = get_check_input("Nickname: ");
    this->_phone_number = get_check_input("Phone Number: ");
    this->_darkest_secret = get_check_input("Darkest Secret: ");
}
