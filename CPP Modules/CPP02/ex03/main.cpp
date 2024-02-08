/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:59:38 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 14:14:22 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include "bsp.hpp"

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 1.0f);
	Point c(1.0f, 0.0f);
	Point point(0.5f, 0.5f);
	Point point2(0.5f, 0.0f);
	Point point3(0.0f, 0.5f);
	Point point4(0.0f, 2.0f);
	Point point5(3.0f, 0.0f);

	std::cout << "Point a: " << a << std::endl;
	std::cout << "Point b: " << b << std::endl;
	std::cout << "Point c: " << c << std::endl;
	std::cout << "Point point: " << point << std::endl;
	std::cout << "Point point2: " << point2 << std::endl;
	std::cout << "Point point3: " << point3 << std::endl;
	std::cout << "Point point4: " << point4 << std::endl;
	std::cout << "Point point5: " << point5 << std::endl;
	
	std::cout << "Point point is inside the triangle: " << bsp(a, b, c, point) << std::endl;
	std::cout << "Point point2 is inside the triangle: " << bsp(a, b, c, point2) << std::endl;
	std::cout << "Point point3 is inside the triangle: " << bsp(a, b, c, point3) << std::endl;
	std::cout << "Point point4 is inside the triangle: " << bsp(a, b, c, point4) << std::endl;
	std::cout << "Point point5 is inside the triangle: " << bsp(a, b, c, point5) << std::endl;
	
	return 0;
}