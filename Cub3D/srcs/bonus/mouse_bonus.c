/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:45:53 by ahsalam           #+#    #+#             */
/*   Updated: 2023/11/20 23:30:38 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	mouse_up(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	if (cub->pitch < 300)
		cub->pitch = cub->pitch + 0.1;
}

static void	mouse_down(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	if (cub->pitch > -300)
		cub->pitch = cub->pitch - 0.1;
}

int	mouse_handle(int x, int y, t_win *win)
{
	if (y < win->mouse_up)
		mouse_up(win);
	if (y > win->mouse_up)
		mouse_down(win);
	if (x > win->mouse_right)
		key_right(win);
	if (x < win->mouse_right)
		key_left(win);
	win->mouse_right = x;
	win->mouse_up = y;
	return (0);
}
