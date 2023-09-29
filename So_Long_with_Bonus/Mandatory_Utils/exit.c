/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:04:06 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/09 18:58:14 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_exit_pos(t_win *win, int x, int y)
{
	if (win->map[y - 1][x] != '1' && win->map[y][x - 1] != '1' && \
		win->map[y + 1][x] == '1' && win->map[y][x + 1] == '1' )
		win->mapstr->exit_pos = 1;
	else if (win->map[y - 1][x] == '1' && win->map[y][x - 1] != '1' && \
		win->map[y + 1][x] != '1' && win->map[y][x + 1] == '1' )
		win->mapstr->exit_pos = 2;
	else if (win->map[y - 1][x] != '1' && win->map[y][x - 1] == '1' && \
		win->map[y + 1][x] == '1' && win->map[y][x + 1] != '1' )
		win->mapstr->exit_pos = 3;
	else if (win->map[y - 1][x] == '1' && win->map[y][x - 1] == '1' && \
		win->map[y + 1][x] != '1' && win->map[y][x + 1] != '1' )
		win->mapstr->exit_pos = 4;
	else if (win->map[y - 1][x] == '1' && win->map[y][x - 1] != '1' && \
		win->map[y + 1][x] != '1' && win->map[y][x + 1] != '1' )
		win->mapstr->exit_pos = 5;
	else if (win->map[y - 1][x] != '1' && win->map[y][x - 1] == '1' && \
		win->map[y + 1][x] != '1' && win->map[y][x + 1] != '1' )
		win->mapstr->exit_pos = 6;
	else
		check_exit_pos1(win, x, y);
}

void	check_exit_pos1(t_win *win, int x, int y)
{
	if (win->map[y - 1][x] != '1' && win->map[y][x - 1] != '1' && \
		win->map[y + 1][x] == '1' && win->map[y][x + 1] != '1' )
		win->mapstr->exit_pos = 7;
	else if (win->map[y - 1][x] != '1' && win->map[y][x - 1] != '1' && \
		win->map[y + 1][x] != '1' && win->map[y][x + 1] == '1' )
		win->mapstr->exit_pos = 8;
	else if (win->map[y - 1][x] != '1' && win->map[y][x - 1] == '1' && \
		win->map[y + 1][x] == '1' && win->map[y][x + 1] == '1' )
		win->mapstr->exit_pos = 9;
	else if (win->map[y - 1][x] == '1' && win->map[y][x - 1] != '1' && \
		win->map[y + 1][x] == '1' && win->map[y][x + 1] == '1' )
		win->mapstr->exit_pos = 10;
	else if (win->map[y - 1][x] == '1' && win->map[y][x - 1] == '1' && \
		win->map[y + 1][x] != '1' && win->map[y][x + 1] == '1' )
		win->mapstr->exit_pos = 11;
	else if (win->map[y - 1][x] == '1' && win->map[y][x - 1] == '1' && \
		win->map[y + 1][x] == '1' && win->map[y][x + 1] != '1' )
		win->mapstr->exit_pos = 12;
	else
		win->mapstr->exit_pos = 13;
}

void	init_exit(t_win *win)
{
	if (win->mapstr->exit_pos == 1)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_UL.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 2)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_DL.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 3)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_UR.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 4)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_RD.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 5)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_RDL.xpm", &win->img->w, &win->img->h);
	else
		init_exit1(win);
}

void	init_exit1(t_win *win)
{
	if (win->mapstr->exit_pos == 6)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_URD.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 7)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_URL.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 8)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_UDL.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 9)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_U.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 10)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_L.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 11)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_D.xpm", &win->img->w, &win->img->h);
	else if (win->mapstr->exit_pos == 12)
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_R.xpm", &win->img->w, &win->img->h);
	else
		win->img->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Exit/Exit_URDL.xpm", &win->img->w, &win->img->h);
}

void	init_player(t_win *win)
{
	if (win->map[win->player_y][win->player_x + 1] == '0')
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_R.xpm", &win->img->w, &win->img->h);
	else if (win->map[win->player_y][win->player_x - 1] == '0')
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_L.xpm", &win->img->w, &win->img->h);
	else if (win->map[win->player_y - 1][win->player_x] == '0')
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_U.xpm", &win->img->w, &win->img->h);
	else
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_D.xpm", &win->img->w, &win->img->h);
}
