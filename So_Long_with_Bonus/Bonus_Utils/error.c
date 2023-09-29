/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:18:12 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/09 18:16:56 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	exit_game_before_window(t_win *win)
{
	free_map(win->map);
	free(win->mapstr);
	free(win->img);
	exit(0);
	return (0);
}

int	exit_game_after_window(t_win *win)
{
	free_map(win->map);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img->back);
	mlx_destroy_image(win->mlx_ptr, win->img->collect);
	mlx_destroy_image(win->mlx_ptr, win->img->exit);
	mlx_destroy_image(win->mlx_ptr, win->img->enemy);
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	mlx_destroy_image(win->mlx_ptr, win->img->wall);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	free(win->mapstr);
	free(win->img);
	exit(0);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	read_esc(int key, t_win *win)
{
	if (key == KEY_ESC)
	{
		ft_printf("Ohhh... You Pressed Esc!!\n");
		exit_game_after_window(win);
	}
	return (0);
}

int	red_cross(t_win *win)
{
	ft_printf("Ohhh... You Closed the game Window!!\n");
	exit_game_after_window(win);
	return (0);
}
