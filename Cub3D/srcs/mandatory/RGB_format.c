/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RGB_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:59:52 by ahsalam           #+#    #+#             */
/*   Updated: 2023/11/20 23:32:37 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	blue(int trgb)
{
	return (trgb & 0xFF);
}

int	transperent(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
