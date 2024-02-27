/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:00:11 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/10 11:10:28 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	game_window(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, \
		win->mapstr->w * TILE_SIZE, win->mapstr->h * TILE_SIZE + 50, "So_Long");
	win->moves = 0;
	win->over = 0;
	win->to_collect = win->mapstr->collect;
	create_image(win);
	display_image(win, -1, -1);
}

void	create_image(t_win *win)
{
	win->img->back = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Floor/Road.xpm", &win->img->w, &win->img->h);
	win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star.xpm", &win->img->w, &win->img->h);
	win->img->wall = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Wall/Brick.xpm", &win->img->w, &win->img->h);
	win->img->lock = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/lock.xpm", &win->img->w, &win->img->h);
	init_player(win);
	init_exit(win);
	win->put_moves = NULL;
}

void	display_image(t_win *win, int y, int x)
{
	while (win->map[++y])
	{
		x = -1;
		while (win->map[y][++x])
		{
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
				win->img->back, x * TILE_SIZE, y * TILE_SIZE);
			if (win->map[y][x] == WALL)
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					win->img->wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (win->map[y][x] == EXIT)
				display_exit(win, y, x);
			else if (win->map[y][x] == PLAYER)
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					win->img->player, x * TILE_SIZE, y * TILE_SIZE);
			else if (win->map[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					win->img->collect, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
	calculate_moves(win, x, y);
}

void	display_exit(t_win *win, int y, int x)
{
	if (win->mapstr->collect != 0)
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					win->img->exit, x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					win->img->lock, x * TILE_SIZE, y * TILE_SIZE);
	}
	else
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					win->img->exit, x * TILE_SIZE, y * TILE_SIZE);
}

void	game_status(t_win *win)
{
	if (win->over == 1)
	{
		ft_printf(PLAYER_WON);
		exit_game_after_window(win);
	}
}
