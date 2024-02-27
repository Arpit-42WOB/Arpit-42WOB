/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 08:43:20 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/10 15:51:36 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	check_errors(t_win *win)
{
	if (check_map_dimensions(win) && check_components(win) \
		&& count_components(win, -1, -1) && check_boundary_walls(win))
	{
		if (check_path(win))
			return (1);
		else
		{
			exit_game_before_window(win);
			return (0);
		}
	}
	else
	{
		exit_game_before_window(win);
		return (0);
	}
}

int	check_map_dimensions(t_win *win)
{
	int	h;
	int	w;
	int	t;

	h = 0;
	t = -1;
	while (win->map[h])
	{
		w = 0;
		while (win->map[h][w])
			w++;
		if (t != -1 && t != w)
			return (error_message(5));
		t = w;
		h++;
	}
	if (h < MIN_MAP_HIEGHT || w < MIN_MAP_WIDTH || \
		h > MAX_MAP_HIEGHT || w > MAX_MAP_WIDTH)
		return (error_message(27));
	win->mapstr->h = h;
	win->mapstr->w = w;
	return (1);
}

int	count_components(t_win *win, int h, int w)
{
	win->mapstr->player = 0;
	win->mapstr->collect = 0;
	win->mapstr->exit = 0;
	while (++w < win->mapstr->w)
	{
		h = -1;
		while (++h < win->mapstr->h)
		{
			if (win->map[h][w] == PLAYER)
			{
				win->mapstr->player++;
				win->player_x = w;
				win->player_y = h;
			}
			else if (win->map[h][w] == COLLECTIBLE)
				win->mapstr->collect++;
			else if (win->map[h][w] == EXIT)
				win->mapstr->exit++;
		}
	}
	if (check_count_of_components(win))
		return (0);
	return (1);
}

int	check_components(t_win *win)
{
	int	h;
	int	w;

	if (!win->map)
		return (0);
	h = 0;
	while (win->map[h])
	{
		w = 0;
		while (win->map[h][w])
		{
			if (win->map[h][w] != PLAYER && win->map[h][w] != COLLECTIBLE \
				&& win->map[h][w] != FLOOR && win->map[h][w] != EXIT \
					&& win->map[h][w] != WALL && win->map[h][w] != ENEMY)
				return (error_message(7));
			if (win->map[h][w] == EXIT)
				check_exit_pos(win, w, h);
			w++;
		}
		h++;
	}
	return (1);
}

int	check_boundary_walls(t_win *win)
{
	int	i;

	i = 0;
	while (i < win->mapstr->w)
	{
		if (win->map[0][i] != WALL || win->map[win->mapstr->h - 1][i] != WALL)
			return (error_message(18));
		i++;
	}
	i = 0;
	while (i < win->mapstr->h)
	{
		if (win->map[i][0] != WALL || win->map[i][win->mapstr->w - 1] != WALL)
			return (error_message(18));
		i++;
	}
	return (1);
}
