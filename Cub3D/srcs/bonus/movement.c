/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:04:13 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/20 23:31:21 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	key_w(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	if (win->imap[(int)(cub->pos_y)][(int)(cub->pos_x + cub->dirx * \
			cub->move_speed)] == 0)
		cub->pos_x += cub->dirx * cub->move_speed;
	if (win->imap[(int)(cub->pos_y + cub->diry * cub->move_speed)] \
			[(int)(cub->pos_x)] == 0)
		cub->pos_y += cub->diry * cub->move_speed;
}

void	key_s(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	if (win->imap[(int)(cub->pos_y)][(int)(cub->pos_x - cub->dirx * \
			cub->move_speed)] == 0)
		cub->pos_x -= cub->dirx * cub->move_speed;
	if (win->imap[(int)(cub->pos_y - cub->diry * cub->move_speed)] \
			[(int)(cub->pos_x)] == 0)
		cub->pos_y -= cub->diry * cub->move_speed;
}

void	key_a(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	if (win->imap[(int)(cub->pos_y)][(int)(cub->pos_x - cub->diry * \
			cub->move_speed)] == 0)
		cub->pos_x -= cub->diry * cub->move_speed;
	if (win->imap[(int)(cub->pos_y + cub->dirx * cub->move_speed)] \
			[(int)(cub->pos_x)] == 0)
		cub->pos_y += cub->dirx * cub->move_speed;
}

void	key_d(t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	if (win->imap[(int)(cub->pos_y)][(int)(cub->pos_x + cub->diry * \
			cub->move_speed)] == 0)
		cub->pos_x += cub->diry * cub->move_speed;
	if (win->imap[(int)(cub->pos_y - cub->dirx * cub->move_speed)] \
			[(int)(cub->pos_x)] == 0)
		cub->pos_y -= cub->dirx * cub->move_speed;
}

int	key_press(int key, t_win *win)
{
	t_cub	*cub;

	cub = win->cub;
	cub->old_timestamp = cub->timestamp;
	cub->timestamp = ft_get_time();
	cub->frame_time = (cub->timestamp - cub->old_timestamp) / 1000.0;
	cub->move_speed = cub->frame_time * 20.0;
	cub->rotation_speed = cub->frame_time * 10.0;
	if (key == 53)
		close_game_win(win);
	if (key == 13)
		key_w(win);
	if (key == 1)
		key_s(win);
	if (key == 0)
		key_a(win);
	if (key == 2)
		key_d(win);
	if (key == 123)
		key_left(win);
	if (key == 124)
		key_right(win);
	return (0);
}
