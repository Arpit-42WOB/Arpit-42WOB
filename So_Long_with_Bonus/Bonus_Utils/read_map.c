/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:36:42 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/09 18:26:35 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	check_map_file(const char *map)
{
	int	i;
	int	fd;

	i = 0;
	while (map[i] != '\0')
		i++;
	fd = ft_strncmp(&map[i - 4], ".ber", 4);
	if (fd != 0)
	{
		error_message(4);
		return (0);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		error_message(3);
		return (0);
	}
	close(fd);
	return (1);
}

char	**load_map(char *file)
{
	char		**map;
	char		*temp;
	char		*line;
	int			fd;

	temp = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(temp, line);
		free (line);
	}
	map = ft_split(temp, '\n');
	free (temp);
	close (fd);
	return (map);
}

void	update_player(t_win *win, char move)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	if (move == 'R')
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_R.xpm", &win->img->w, &win->img->h);
	else if (move == 'L')
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_L.xpm", &win->img->w, &win->img->h);
	else if (move == 'D')
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_D.xpm", &win->img->w, &win->img->h);
	else if (move == 'U')
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_U.xpm", &win->img->w, &win->img->h);
}

int	error_message(int code)
{
	if (code == 3)
		ft_printf("Unable to Read File Data!!\n");
	else if (code == 4)
		ft_printf("Invalid Map File Format\n");
	else if (code == 5)
		ft_printf("Width of Map is not Same for all Rows!!\n");
	else if (code == 6)
		ft_printf("Map is Either too Big or too Small to be Displayed!!\n");
	else if (code == 7)
		ft_printf("Found an Unknown Variable in Map!!\n");
	else if (code == 8)
		ft_printf("Map should be closed with Walls from all 4 sides!!\n");
	else if (code == 9)
		ft_printf("All Collectibles cannot be collected!!\n");
	else if (code == 10)
		ft_printf("Player cannot reach Exit!!\n");
	else
		ft_printf("Error\n");
	return (0);
}

int	check_count_of_components(t_win *win)
{
	int	t;

	t = 0;
	if (win->mapstr->collect < 1)
	{
		ft_printf("No. of Collectibles cannot be less than 1\n");
		t = 1;
	}
	if (win->mapstr->exit != 1)
	{
		ft_printf("No. of Exits should only be 1\n");
		t = 1;
	}
	if (win->mapstr->player != 1)
	{
		ft_printf("No. of Players should only be 1\n");
		t = 1;
	}
	return (t);
}
