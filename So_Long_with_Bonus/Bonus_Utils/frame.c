/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:25:43 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/09 18:11:22 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	update_enemy_n_collecible(t_win *win, size_t t)
{
	if (t % 15 == 1)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E1.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_B3.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 2)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E2.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_B2.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 3)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E3.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_B1.xpm", &win->img->w, &win->img->h);
	}
	else
		update_enemy_n_collecible1(win, t);
}

void	update_enemy_n_collecible1(t_win *win, size_t t)
{
	if (t % 15 == 4)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E4.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 5)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E5.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_U1.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 6)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E6.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_U2.xpm", &win->img->w, &win->img->h);
	}
	else
		update_enemy_n_collecible2(win, t);
}

void	update_enemy_n_collecible2(t_win *win, size_t t)
{
	if (t % 15 == 7)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E7.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_U3.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 8)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E8.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_U4.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 9)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E9.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_U3.xpm", &win->img->w, &win->img->h);
	}
	else 
		update_enemy_n_collecible3(win, t);
}

void	update_enemy_n_collecible3(t_win *win, size_t t)
{
	if (t % 15 == 10)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E10.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_U2.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 11)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E11.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_U1.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 12)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E12.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star.xpm", &win->img->w, &win->img->h);
	}
	else
		update_enemy_n_collecible4(win, t);
}

void	update_enemy_n_collecible4(t_win *win, size_t t)
{
	if (t % 15 == 13)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E13.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 14)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E14.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_B1.xpm", &win->img->w, &win->img->h);
	}
	else if (t % 15 == 0)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Enemy/E15.xpm", &win->img->w, &win->img->h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Collectible/Star_B2.xpm", &win->img->w, &win->img->h);
	}
}
