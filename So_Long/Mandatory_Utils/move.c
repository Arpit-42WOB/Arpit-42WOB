/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:45:42 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/10 11:26:48 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_hooks(int key, t_win *win)
{
	int	c;

	c = win->moves;
	if (win->over)
		return (0);
	else if (key == KEY_W || key == KEY_UP)
		move_up(win);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(win);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(win);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(win);
	if (c != win->moves)
		ft_printf("Moves: %d\n", win->moves);
	return (0);
}

void	move_up(t_win *win)
{
	update_player(win, KEY_UP);
	if (win->map[win->player_y - 1][win->player_x] != WALL && \
		(win->map[win->player_y - 1][win->player_x] != EXIT \
			|| win->mapstr->collect == 0))
	{
		if (win->map[win->player_y - 1][win->player_x] == COLLECTIBLE)
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y - 1][win->player_x] = PLAYER;
		}
		else if (win->map[win->player_y - 1][win->player_x] == FLOOR)
		{
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y - 1][win->player_x] = PLAYER;
		}
		else
			win->over = 1;
		win->moves++;
		win->player_y--;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	display_image(win, -1, -1);
}

void	move_down(t_win *win)
{
	update_player(win, KEY_DOWN);
	if (win->map[win->player_y + 1][win->player_x] != WALL && 
		(win->map[win->player_y + 1][win->player_x] != EXIT \
			|| win->mapstr->collect == 0))
	{
		if (win->map[win->player_y + 1][win->player_x] == COLLECTIBLE)
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y + 1][win->player_x] = PLAYER;
		}
		else if (win->map[win->player_y + 1][win->player_x] == FLOOR)
		{
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y + 1][win->player_x] = PLAYER;
		}
		else
			win->over = 1;
		win->moves++;
		win->player_y++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	display_image(win, -1, -1);
}

void	move_left(t_win *win)
{
	update_player(win, KEY_LEFT);
	if (win->map[win->player_y][win->player_x - 1] != WALL && 
		(win->map[win->player_y][win->player_x - 1] != EXIT \
			|| win->mapstr->collect == 0))
	{
		if (win->map[win->player_y][win->player_x - 1] == COLLECTIBLE)
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y][win->player_x - 1] = PLAYER;
		}
		else if (win->map[win->player_y][win->player_x - 1] == FLOOR)
		{
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y][win->player_x - 1] = PLAYER;
		}
		else
			win->over = 1;
		win->moves++;
		win->player_x--;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	display_image(win, -1, -1);
}

void	move_right(t_win *win)
{
	update_player(win, KEY_RIGHT);
	if (win->map[win->player_y][win->player_x + 1] != WALL && 
		(win->map[win->player_y][win->player_x + 1] != EXIT \
			|| win->mapstr->collect == 0))
	{
		if (win->map[win->player_y][win->player_x + 1] == COLLECTIBLE)
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y][win->player_x + 1] = PLAYER;
		}
		else if (win->map[win->player_y][win->player_x + 1] == FLOOR)
		{
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y][win->player_x + 1] = PLAYER;
		}
		else
			win->over = 1;
		win->moves++;
		win->player_x++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	display_image(win, -1, -1);
}
