/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:00:46 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 13:23:15 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(Point const &obj);
	Point(float const x, float const y);
	Point &operator=(Point const &obj);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
};

std::ostream &operator<<(std::ostream &out, Point const &obj);

#endif