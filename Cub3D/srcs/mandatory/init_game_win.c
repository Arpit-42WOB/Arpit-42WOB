/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:18:53 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/20 23:32:11 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_player_dir(t_win *win)
{
	if (win->player_dir == 'E')
	{
		win->cub->dirx = -1;
		win->cub->planey = 0.66;
	}
	if (win->player_dir == 'W')
	{
		win->cub->dirx = 1;
		win->cub->planey = -0.66;
	}
	if (win->player_dir == 'N')
	{
		win->cub->diry = -1;
		win->cub->planex = -0.66;
	}
	if (win->player_dir == 'S')
	{
		win->cub->diry = 1;
		win->cub->planex = 0.66;
	}
}

int	init_win(t_win *win)
{
	win->cub = ft_calloc(sizeof(t_cub), 1);
	if (!win->cub)
		return (0);
	win->mlx_ptr = mlx_init();
	win->cub->mlx_ptr = win->mlx_ptr;
	win->win_width = 1200;
	win->win_height = 900;
	win->t_height = 64;
	win->t_width = 64;
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->win_width, \
					win->win_height, "Cub3D");
	win->cub->win_ptr = win->win_ptr;
	win->tex = (u_int32_t **)ft_calloc(sizeof(u_int32_t *), 4);
	if (win->tex == NULL)
		return (0);
	return (1);
}

int	*convert(unsigned char *img_data, int img_w, int img_h)
{
	int	*int_data;
	int	i;
	int	j;
	int	k;

	int_data = (int *)malloc(sizeof(int) * img_w * img_h);
	if (!int_data)
		return (NULL);
	i = -1;
	while (++i < img_h)
	{
		j = -1;
		while (++j < img_w)
		{
			k = (i * img_w + j) * 4;
			int_data[i * img_w + j] = (img_data[k + 3] << 24) | \
					(img_data[k + 2] << 16) | (img_data[k + 1] << 8) | \
					(img_data[k]);
		}
	}
	return (int_data);
}

int	init_textures(t_win *win)
{
	unsigned char	*img_data;
	int				bpp;

	bpp = 0;
	img_data = (unsigned char *)mlx_get_data_addr(win->east_wall.img_ptr, \
				&bpp, &win->line_size, &win->cub->endian);
	win->tex[0] = (uint32_t *)convert(img_data, win->t_width, win->t_height);
	if (!win->tex[0])
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(win->north_wall.img_ptr, \
				&bpp, &win->line_size, &win->cub->endian);
	win->tex[1] = (uint32_t *)convert(img_data, win->t_width, win->t_height);
	if (!win->tex[1])
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(win->west_wall.img_ptr, \
				&bpp, &win->line_size, &win->cub->endian);
	win->tex[2] = (uint32_t *)convert(img_data, win->t_width, win->t_height);
	if (!win->tex[2])
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(win->south_wall.img_ptr, \
				&bpp, &win->line_size, &win->cub->endian);
	win->tex[3] = (uint32_t *)convert(img_data, win->t_width, win->t_height);
	if (!win->tex[3])
		return (0);
	return (1);
}
