/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:59:57 by ahsalam           #+#    #+#             */
/*   Updated: 2023/11/20 23:32:32 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_calulate_draw(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	cub->line_height = (int)(win->win_height / cub->perp_wall_dist);
	cub->draw_start = -cub->line_height / 2 + win->win_height / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = cub->line_height / 2 + win->win_height / 2;
	if (cub->draw_end >= win->win_height)
		cub->draw_end = win->win_height - 1;
	cub->texture_num = win->imap[cub->map_y][cub->map_x];
	if (cub->side % 2 == 0)
		cub->wall_x = cub->pos_y + cub->perp_wall_dist * cub->ray_diry;
	else
		cub->wall_x = cub->pos_x + cub->perp_wall_dist * cub->ray_dirx;
	cub->wall_x -= floor(cub->wall_x);
	cub->tex_x = (int)(cub->wall_x * (double)win->t_width);
}

void	ft_draw_wall(t_win *win, int i)
{
	int		j;
	t_cub	*cub;

	cub = win->cub;
	if (cub->side % 2 == 0 && cub->ray_dirx > 0)
		cub->tex_x = win->t_width - cub->tex_x - 1;
	if (cub->side % 2 == 1 && cub->ray_diry < 0)
		cub->tex_x = win->t_width - cub->tex_x - 1;
	cub->step = 1.0 * win->t_height / cub->line_height;
	cub->tex_pos = (cub->draw_start - win->win_height / 2 + \
					cub->line_height / 2) * cub->step;
	j = cub->draw_start;
	while (j < cub->draw_end)
	{
		cub->tex_y = (int)cub->tex_pos & (win->t_height - 1);
		cub->tex_pos += cub->step;
		cub->colors = win->tex[cub->texture_num + cub->side - 1] \
					[win->t_height * cub->tex_y + cub->tex_x];
		add_pixel(win, i, j, cub->colors);
		j++;
	}
}

void	side_inspect(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	if (cub->side == 0)
	{
		if (cub->map_x > cub->pos_x)
			cub->side = 2;
		cub->perp_wall_dist = (cub->side_dist_x - cub->delta_dist_x);
	}
	else
	{
		if (cub->map_y > cub->pos_y)
			cub->side = 3;
		cub->perp_wall_dist = (cub->side_dist_y - cub->delta_dist_y);
	}
}

void	ft_wall_hit_dda(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	while (cub->hit == 0)
	{
		if (cub->side_dist_x < cub->side_dist_y)
		{
			cub->side_dist_x += cub->delta_dist_x;
			cub->map_x += cub->step_x;
			cub->side = 0;
		}
		else
		{
			cub->side_dist_y += cub->delta_dist_y;
			cub->map_y += cub->step_y;
			cub->side = 1;
		}
		if (win->imap[cub->map_y][cub->map_x] > 0)
			cub->hit = 1;
	}
	side_inspect(win);
}
