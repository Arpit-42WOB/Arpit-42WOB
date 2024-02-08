/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:33:23 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/01 14:50:47 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();

	Fixed &operator=(const Fixed &f);
	bool	operator>(const Fixed &f) const;
	bool	operator<(const Fixed &f) const;
	bool	operator>=(const Fixed &f) const;
	bool	operator<=(const Fixed &f) const;
	bool	operator==(const Fixed &f) const;
	bool	operator!=(const Fixed &f) const;
	Fixed	operator+(const Fixed &f) const;
	Fixed	operator-(const Fixed &f) const;
	Fixed	operator*(const Fixed &f) const;
	Fixed	operator/(const Fixed &f) const;
	Fixed	operator++(int);
	Fixed	operator++();
	Fixed	operator--(int);
	Fixed	operator--();
	static	Fixed	&min(Fixed &a, Fixed &b);
	static	Fixed	&max(Fixed &a, Fixed &b);
	static	Fixed	const &min(Fixed const &a, Fixed const &b);
	static	Fixed	const &max(Fixed const &a, Fixed const &b);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif