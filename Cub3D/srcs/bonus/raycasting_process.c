/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:00:09 by ahsalam           #+#    #+#             */
/*   Updated: 2023/11/20 23:31:33 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_side_distance(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	if (cub->ray_dirx < 0)
	{
		cub->step_x = -1;
		cub->side_dist_x = (cub->pos_x - cub->map_x) * cub->delta_dist_x;
	}
	else
	{
		cub->step_x = 1;
		cub->side_dist_x = (cub->map_x + 1.0 - cub->pos_x) * cub->delta_dist_x;
	}
	cub = win->cub;
	if (cub->ray_diry < 0)
	{
		cub->step_y = -1;
		cub->side_dist_y = (cub->pos_y - cub->map_y) * cub->delta_dist_y;
	}
	else
	{
		cub->step_y = 1;
		cub->side_dist_y = (cub->map_y + 1.0 - cub->pos_y) * cub->delta_dist_y;
	}
}

void	ft_raycasting_init(t_win *win, int i)
{
	t_cub	*cub;

	cub = win->cub;
	cub->cam_x = 2 * i / (double)win->win_width - 1;
	cub->ray_dirx = cub->dirx + cub->planex * cub->cam_x;
	cub->ray_diry = cub->diry + cub->planey * cub->cam_x;
	cub->map_x = (int)cub->pos_x;
	cub->map_y = (int)cub->pos_y;
	cub->delta_dist_x = fabs(1 / cub->ray_dirx);
	cub->delta_dist_y = fabs(1 / cub->ray_diry);
	cub->hit = 0;
}

void	ft_wall_cast(t_win *win)
{
	int		i;
	t_cub	*cub;

	cub = win->cub;
	i = 0;
	while (i < win->win_width)
	{
		ft_raycasting_init(win, i);
		ft_side_distance(win);
		ft_wall_hit_dda(win);
		ft_calulate_draw(win);
		ft_draw_wall(win, i);
		i++;
	}
}

void	ft_floor_ground(t_win *win)
{
	int		column;
	int		floorpixel;
	int		ceilingpixel;

	column = -1;
	while (++column < win->win_width)
	{
		floorpixel = -1;
		while (++floorpixel < win->win_height / 2)
			add_pixel(win, column, win->win_height \
									- floorpixel - 1, win->floor_color);
		ceilingpixel = -1;
		while (++ceilingpixel < win->win_height / 2)
			add_pixel(win, column, ceilingpixel, win->ceiling_color);
	}
}

int	ft_raycasting_process(t_win *win)
{
	t_cub	*cub;

	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	win->cub->timestamp = ft_get_time();
	cub = win->cub;
	cub->img = mlx_new_image(win->mlx_ptr, win->win_width, win->win_height);
	cub->img_addr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel, \
					&cub->line_length, &cub->endian);
	mlx_hook(win->win_ptr, 6, 0, mouse_handle, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, key_press, win);
	ft_floor_ground(win);
	ft_wall_cast(win);
	ft_minimap(win, -1, 0);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, cub->img, 0, 0);
	mlx_destroy_image(win->mlx_ptr, cub->img);
	return (0);
}
