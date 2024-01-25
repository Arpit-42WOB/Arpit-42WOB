/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:22:24 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/24 13:43:46 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"
# include "./Header.hpp"

class PhoneBook
{
	private:
			int		_index;
			int		_size;
			Contact	_contacts[8];

	public:
			PhoneBook(void);
			void add(void);
			void search(void);
			void search_display(int spc);
			Contact get_contact(int index);
};

#endif