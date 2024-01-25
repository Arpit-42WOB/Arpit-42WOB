/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:44:59 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/23 20:39:48 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "./Header.hpp"

class Contact
{
		private:
				std::string		_first_name;
				std::string		_last_name;
				std::string		_nick_name;
				std::string		_phone_number;
				std::string		_darkest_secret;

		public:
				std::string		get_first_name(void);
				std::string		get_last_name(void);
				std::string		get_nick_name(void);
				std::string		get_phone_number(void);
				std::string		get_darkest_secret(void);
				void			get_full_info(void);
				void			set_full_info(void);
};

#endif