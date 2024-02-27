/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:05:03 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/10 11:16:42 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_path(t_win *win)
{
	int		i;
	char	**map_dup;

	win->to_collect = 0;
	win->to_exit = 0;
	map_dup = malloc(sizeof(char *) * (win->mapstr->h + 1));
	if (!map_dup)
		return (0);
	i = -1;
	while (win->map[++i])
		map_dup[i] = ft_strdup(win->map[i]);
	map_dup[i] = NULL;
	check_move(map_dup, win->player_x, win->player_y, win);
	free_map(map_dup);
	if (win->to_collect != (win->mapstr->collect))
		return (error_message(9));
	else if (win->to_exit != 1)
		return (error_message(10));
	else
		return (1);
}

void	check_move(char **map_dup, int x, int y, t_win *win)
{
	if (map_dup[y][x] == COLLECTIBLE)
		win->to_collect += 1;
	if (map_dup[y][x] == EXIT)
	{
		win->to_exit += 1;
		map_dup[y][x] = WALL;
		return ;
	}
	map_dup[y][x] = FLAG;
	if (map_dup[y][x + 1] != WALL && map_dup[y][x + 1] != FLAG \
			&& map_dup[y][x + 1])
		check_move(map_dup, x + 1, y, win);
	if (map_dup[y][x - 1] != WALL && map_dup[y][x - 1] != FLAG \
			&& map_dup[y][x - 1])
		check_move(map_dup, x - 1, y, win);
	if (map_dup[y + 1][x] != WALL && map_dup[y + 1][x] != FLAG \
			&& map_dup[y + 1][x])
		check_move(map_dup, x, y + 1, win);
	if (map_dup[y - 1][x] != WALL && map_dup[y - 1][x] != FLAG \
			&& map_dup[y - 1][x])
		check_move(map_dup, x, y - 1, win);
}

void	calculate_moves(t_win *win, int x, int y)
{
	char	*moves;
	char	*s;
	char	*c;
	char	*collected;

	game_status(win);
	s = ft_strdup("No. of Moves: ");
	moves = ft_itoa(win->moves);
	win->put_moves = ft_strjoin(s, moves);
	c = ft_strdup("Star Collected: ");
	collected = ft_itoa(win->to_collect - win->mapstr->collect);
	win->put_collect = ft_strjoin(c, collected);
	mlx_string_put(win->mlx_ptr, win->win_ptr, ((x * TILE_SIZE) / 2) - 50, \
					y * TILE_SIZE + 20, 0xFFFFFF, win->put_moves);
	mlx_string_put(win->mlx_ptr, win->win_ptr, ((x * TILE_SIZE) / 2) - 58, \
					y * TILE_SIZE + 40, 0xFFFFFF, win->put_collect);
	free(win->put_collect);
	free(win->put_moves);
	free(moves);
	free(collected);
}
