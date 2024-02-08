/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:00:43 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 14:11:36 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(Point const &obj) : _x(obj.getX()), _y(obj.getY())
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point &Point::operator=(Point const &obj)
{
	*(const_cast<Fixed *>(&_x)) = obj.getX();
	*(const_cast<Fixed *>(&_y)) = obj.getY();
	return *this;
}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

std::ostream &operator<<(std::ostream &out, Point const &obj)
{
	out << "Point(" << obj.getX() << ", " << obj.getY() << ")";
	return out;
}

