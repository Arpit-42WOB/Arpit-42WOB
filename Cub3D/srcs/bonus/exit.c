/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:43:59 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/20 23:30:50 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_textures(t_win *win)
{
	int	i;

	if (win->tex)
	{
		i = 0;
		while (i < 4)
		{
			if (win->tex[i] != NULL)
				free(win->tex[i]);
			i++;
		}
		free(win->tex);
	}
	if (win->north_wall.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->north_wall.img_ptr);
	if (win->south_wall.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->south_wall.img_ptr);
	if (win->east_wall.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->east_wall.img_ptr);
	if (win->west_wall.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->west_wall.img_ptr);
}

void	free_win(t_win	*win)
{
	int	i;

	if (win->imap != NULL)
	{
		i = 0;
		while (i < (int)ft_strstr_len(win->map))
		{
			free(win->imap[i]);
			i++;
		}
		free(win->imap);
	}
	free_textures(win);
	if (win->map)
		ft_strstr_free(win->map);
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->cub)
		free(win->cub);
}

int	close_game_win(t_win *win)
{
	free_win(win);
	exit(0);
}
