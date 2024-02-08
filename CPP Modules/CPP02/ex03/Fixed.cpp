/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:59:31 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 14:15:35 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_rawBits = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int i)
{
	//std::cout << "Int constructor called" << std::endl;
	_rawBits = i << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called" << std::endl;
	_rawBits = (int)roundf(f * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	//std::cout << "Assignation operator called" << std::endl;
	_rawBits = f.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &f) const
{
	return _rawBits > f.getRawBits();
}

bool	Fixed::operator<(const Fixed &f) const
{
	return _rawBits < f.getRawBits();
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return _rawBits >= f.getRawBits();
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return _rawBits <= f.getRawBits();
}

bool	Fixed::operator==(const Fixed &f) const
{
	return _rawBits == f.getRawBits();
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return _rawBits != f.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	Fixed ret;
	ret.setRawBits(_rawBits + f.getRawBits());
	return ret;
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	Fixed ret;
	ret.setRawBits(_rawBits - f.getRawBits());
	return ret;
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	Fixed ret;
	ret.setRawBits((_rawBits * f.getRawBits()) >> _fractionalBits);
	return ret;
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	Fixed ret;
	ret.setRawBits((_rawBits << _fractionalBits) / f.getRawBits());
	return ret;
}

Fixed	Fixed::operator++(int)
{
	Fixed ret(*this);
	_rawBits++;
	return ret;
}

Fixed	Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed ret(*this);
	_rawBits--;
	return ret;
}

Fixed	Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}

int		Fixed::getRawBits(void) const
{
	return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);
}

int		Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return out;
}
