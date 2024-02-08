/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:59:28 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 14:00:40 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

Fixed calculateArea(Point const &a, Point const &b, Point const &c)
{
	Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed total_area = calculateArea(a, b, c);
	Fixed area1 = calculateArea(a, b, point);
	Fixed area2 = calculateArea(a, c, point);
	Fixed area3 = calculateArea(b, c, point);
	if (total_area == area1 + area2 + area3)
		return true;
	return false;
}