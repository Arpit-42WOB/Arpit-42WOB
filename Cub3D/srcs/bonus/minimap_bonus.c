/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:34:32 by ahsalam           #+#    #+#             */
/*   Updated: 2023/11/20 23:30:29 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	draw_map(t_win *win, int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 20)
	{
		j = -1;
		while (++j < 20)
			add_pixel(win, x + i, y + j, color);
	}
}

static void	draw_window(t_win *win)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 200)
	{
		j = -1;
		while (++j < 200)
		{
			if (i < 10 || j < 10 || i > 190 || j > 190)
				add_pixel(win, i, j, create_trgb(255, 255, 255, 255));
			else
				add_pixel(win, i, j, create_trgb(0, 255, 255, 255));
		}
	}
}

void	ft_minimap(t_win *win, int i, int j)
{
	draw_window(win);
	draw_map(win, 90, 80, create_trgb(0, 0, 0, 255));
	while (++i < (int)ft_strstr_len(win->map))
	{
		j = -1;
		while (++j < (int)ft_strlen(win->map[i]) - 1)
		{
			if ((int)win->cub->pos_x - j < 5 && (int)win->cub->pos_x - j > -4 \
			&& (int)win->cub->pos_y - i < 5 && (int)win->cub->pos_y - i > -4)
				if (win->imap[i][j] == 1)
					draw_map(win, 90 - ((int)win->cub->pos_y - i) * 20, 80 - \
				((int)win->cub->pos_x - j) * 20, create_trgb(0, 0, 255, 255));
		}
	}
}
