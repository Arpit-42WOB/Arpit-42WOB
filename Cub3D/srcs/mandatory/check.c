/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:53:14 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/21 18:18:49 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_components(t_win *win, char **map, int i)
{
	int	j;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' \
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				if (win->player_dir != 0)
					return (0);
				else
				{
					win->player_dir = map[i][j];
					win->cub->pos_x = j + 0.5;
					win->cub->pos_y = i + 0.5;
					map[i][j] = '0';
				}
			}
			else if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0')
				return (0);
		}
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' \
				|| map[i][j] == 'S' || map[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == (int)ft_strstr_len(map) - 1 \
					|| j == (int)ft_strlen(map[i]) - 2)
					return (0);
				else if (((int)ft_strlen(map[i - 1]) < j + 2 \
				|| map[i - 1][j] == ' ') || ((int)ft_strlen(map[i + 1]) < j + 1 \
				|| map[i + 1][j] == '\n' || map[i + 1][j] == ' ') \
				|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

int	check_empty(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_empty_line(map[i]))
			break ;
		i++;
	}
	while (map[i])
	{
		if (!is_empty_line(map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	map_check_errors(t_win *win, char **file_content)
{
	if (!check_empty(win->map))
	{
		ft_strstr_free(file_content);
		ft_print_error_and_exit(win, "Map has empty lines\n");
	}
	if (!check_walls(win->map))
	{
		ft_strstr_free(file_content);
		ft_print_error_and_exit(win, "Map is not surrounded by walls\n");
	}
}

void	init_map(t_win *win, char **file_content)
{
	int	i;

	win->map = get_map(file_content);
	if (!win->map)
	{
		ft_strstr_free(file_content);
		ft_print_error_and_exit(win, "Map not found\n");
	}
	fill_with_ones(win);
	make_map_rectangular(win);
	map_check_errors(win, file_content);
	i = 0;
	while (win->map[i])
	{
		reverse_str(win->map[i]);
		i++;
	}
	i = -1;
	if (!check_components(win, win->map, i) || !win->player_dir)
	{
		ft_strstr_free(file_content);
		ft_print_error_and_exit(win, "Invalid map content\n");
	}
}
