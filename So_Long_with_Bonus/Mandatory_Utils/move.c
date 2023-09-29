/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:45:42 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/09 18:58:22 by amehrotr         ###   ########.fr       */
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
	update_player(win, 'U');
	if (win->map[win->player_y - 1][win->player_x] != '1' && \
		(win->map[win->player_y - 1][win->player_x] != 'E' \
			|| win->mapstr->collect == 0))
	{
		if (win->map[win->player_y - 1][win->player_x] == 'C')
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = '0';
			win->map[win->player_y - 1][win->player_x] = 'P';
		}
		else if (win->map[win->player_y - 1][win->player_x] == '0')
		{
			win->map[win->player_y][win->player_x] = '0';
			win->map[win->player_y - 1][win->player_x] = 'P';
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
	update_player(win, 'D');
	if (win->map[win->player_y + 1][win->player_x] != '1' && 
		(win->map[win->player_y + 1][win->player_x] != 'E' \
			|| win->mapstr->collect == 0))
	{
		if (win->map[win->player_y + 1][win->player_x] == 'C')
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = '0';
			win->map[win->player_y + 1][win->player_x] = 'P';
		}
		else if (win->map[win->player_y + 1][win->player_x] == '0')
		{
			win->map[win->player_y][win->player_x] = '0';
			win->map[win->player_y + 1][win->player_x] = 'P';
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
	update_player(win, 'L');
	if (win->map[win->player_y][win->player_x - 1] != '1' && 
		(win->map[win->player_y][win->player_x - 1] != 'E' \
			|| win->mapstr->collect == 0))
	{
		if (win->map[win->player_y][win->player_x - 1] == 'C')
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = '0';
			win->map[win->player_y][win->player_x - 1] = 'P';
		}
		else if (win->map[win->player_y][win->player_x - 1] == '0')
		{
			win->map[win->player_y][win->player_x] = '0';
			win->map[win->player_y][win->player_x - 1] = 'P';
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
	update_player(win, 'R');
	if (win->map[win->player_y][win->player_x + 1] != '1' && 
		(win->map[win->player_y][win->player_x + 1] != 'E' \
			|| win->mapstr->collect == 0))
	{
		if (win->map[win->player_y][win->player_x + 1] == 'C')
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = '0';
			win->map[win->player_y][win->player_x + 1] = 'P';
		}
		else if (win->map[win->player_y][win->player_x + 1] == '0')
		{
			win->map[win->player_y][win->player_x] = '0';
			win->map[win->player_y][win->player_x + 1] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		win->player_x++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	display_image(win, -1, -1);
}
