/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:36:42 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/10 11:27:06 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
		error_message(8);
		return (0);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		error_message(2);
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

void	update_player(t_win *win, int move)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	if (move == KEY_RIGHT)
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_R.xpm", &win->img->w, &win->img->h);
	else if (move == KEY_LEFT)
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_L.xpm", &win->img->w, &win->img->h);
	else if (move == KEY_DOWN)
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_D.xpm", &win->img->w, &win->img->h);
	else if (move == KEY_UP)
		win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, \
		"textures/Player/Car_U.xpm", &win->img->w, &win->img->h);
}

int	error_message(int code)
{
	errno = code;
	if (code == 2)
		perror(FILE_ERROR);
	else if (code == 8)
		perror(FILE_NAME_ERROR);
	else if (code == 5)
		ft_printf(WIDTH_NOT_SAME);
	else if (code == 27)
		perror(MAP_SIZE_ISSUE);
	else if (code == 7)
		ft_printf(UNKNOWN_CHAR);
	else if (code == 18)
		ft_printf(FOUR_SIDE_WALL);
	else if (code == 9)
		ft_printf(CAN_NOT_COLLECT);
	else if (code == 10)
		ft_printf(EXIT_NOT_REACHABLE);
	else
	{
		errno = 5;
		perror(strerror(errno));
	}
	return (0);
}

int	check_count_of_components(t_win *win)
{
	int	t;

	t = 0;
	if (win->mapstr->collect < 1)
	{
		ft_printf(ZERO_COLLECT);
		t = 1;
	}
	if (win->mapstr->exit != 1)
	{
		ft_printf(ONE_EXIT);
		t = 1;
	}
	if (win->mapstr->player != 1)
	{
		ft_printf(ONE_PLAYER);
		t = 1;
	}
	return (t);
}
