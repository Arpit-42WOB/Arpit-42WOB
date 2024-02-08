/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:33:57 by amehrotr          #+#    #+#             */
/*   Updated: 2024/02/06 13:39:44 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
# define BSP_HPP

#include "Point.hpp"

Fixed calculateArea(Point const &a, Point const &b, Point const &c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif