/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:35:52 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/01 14:54:14 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << this->_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << this->_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = f.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &f) const
{
	return (this->_value > f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (this->_value < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (this->_value >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (this->_value <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (this->_value == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (this->_value != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	Fixed ret;
	ret.setRawBits(this->_value + f.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	Fixed ret;
	ret.setRawBits(this->_value - f.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	Fixed ret;
	ret.setRawBits((this->_value * f.getRawBits()) >> this->_bits);
	return (ret);
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	Fixed ret;
	ret.setRawBits((this->_value << this->_bits) / f.getRawBits());
	return (ret);
}

Fixed	Fixed::operator++(int)
{
	Fixed ret(*this);
	this->_value++;
	return (ret);
}

Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed ret(*this);
	this->_value--;
	return (ret);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

std::ostream &operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return (o);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}
