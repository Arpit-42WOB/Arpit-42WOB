/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:01:10 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/21 17:01:51 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	add_color_varialble(int *color, char *rgb)
{
	char	**colors;
	int		i;

	colors = ft_split(rgb, ',');
	i = 0;
	while (colors && colors[i])
	{
		if (*color != 0 || (i == 3 || (i < 2 && !colors[i + 1])) || \
			!check_if_nums(colors[i]) || ft_atoi(colors[i]) > 255)
		{
			ft_strstr_free(colors);
			return (1);
		}
		i++;
	}
	*color = create_trgb(0, ft_atoi(colors[0]), ft_atoi(colors[1]), \
				ft_atoi(colors[2]));
	ft_strstr_free(colors);
	return (0);
}

int	add_path_variable(t_win *win, t_img *img, char *path)
{
	if ((*img).img_ptr != NULL)
		return (1);
	*img = read_img(win->mlx_ptr, path);
	if ((*img).img_ptr == NULL)
		return (1);
	return (0);
}

int	pick_variable(t_win *win, char **var)
{
	if (ft_strncmp(var[0], "NO", 3) == 0)
		return (add_path_variable(win, &win->north_wall, var[1]));
	if (ft_strncmp(var[0], "SO", 3) == 0)
		return (add_path_variable(win, &win->south_wall, var[1]));
	if (ft_strncmp(var[0], "WE", 3) == 0)
		return (add_path_variable(win, &win->west_wall, var[1]));
	if (ft_strncmp(var[0], "EA", 3) == 0)
		return (add_path_variable(win, &win->east_wall, var[1]));
	if (ft_strncmp(var[0], "F", 2) == 0)
		return (add_color_varialble(&win->floor_color, var[1]));
	if (ft_strncmp(var[0], "C", 2) == 0)
		return (add_color_varialble(&win->ceiling_color, var[1]));
	return (1);
}

void	init_map_variables(t_win *win, char **file_content, \
						int i, int var_count)
{
	char	**var;

	while (file_content[i])
	{
		while (is_empty_line(file_content[i]))
			i++;
		var = ft_spliting(file_content[i]);
		if (*var != NULL)
		{
			if (ft_strstr_len(var) != 2 || pick_variable(win, var))
			{
				ft_strstr_free(var);
				ft_strstr_free(file_content);
				ft_print_error_and_exit(win, "Invalid Map\n");
			}
			else
				var_count++;
		}
		ft_strstr_free(var);
		if (var_count == 6)
			break ;
		i++;
	}
}

void	init_map_data(t_win *win, char *path)
{
	char	**file_content;

	file_content = read_map(win, path);
	init_map_variables(win, file_content, 0, 0);
	init_map(win, file_content);
	ft_strstr_free(file_content);
}
