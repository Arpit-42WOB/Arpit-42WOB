/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:59:34 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/20 23:33:46 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	key_left(t_win	*win)
{
	t_cub	*cub;

	cub = win->cub;
	cub->old_dir_x = cub->dirx;
	cub->dirx = cub->dirx * cos(cub->rotation_speed) - cub->diry * \
				sin(cub->rotation_speed);
	cub->diry = cub->old_dir_x * sin(cub->rotation_speed) + cub->diry * \
				cos(cub->rotation_speed);
	cub->old_plane_x = cub->planex;
	cub->planex = cub->planex * cos(cub->rotation_speed) - cub->planey * \
				sin(cub->rotation_speed);
	cub->planey = cub->old_plane_x * sin(cub->rotation_speed) + cub->planey \
				* cos(cub->rotation_speed);
}

void	key_right(t_win	*win)
{
	t_cub	*cub;

	cub = win->cub;
	cub->old_dir_x = cub->dirx;
	cub->dirx = cub->dirx * cos(-cub->rotation_speed) - cub->diry * \
				sin(-cub->rotation_speed);
	cub->diry = cub->old_dir_x * sin(-cub->rotation_speed) + cub->diry * \
				cos(-cub->rotation_speed);
	cub->old_plane_x = cub->planex;
	cub->planex = cub->planex * cos(-cub->rotation_speed) - cub->planey * \
				sin(-cub->rotation_speed);
	cub->planey = cub->old_plane_x * sin(-cub->rotation_speed) + cub->planey \
					* cos(-cub->rotation_speed);
}
