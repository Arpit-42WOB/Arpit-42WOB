/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:53:34 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/21 18:19:30 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**get_map(char **file_content)
{
	int		var_count;
	int		i;
	char	**map;
	int		j;

	var_count = 0;
	i = 0;
	while (file_content[i])
	{
		if (!is_empty_line(file_content[i]))
		{
			if (var_count == 6)
				break ;
			var_count++;
		}
		i++;
	}
	if (!file_content[i])
		return (NULL);
	j = ft_strstr_len(file_content) - 1;
	while (is_empty_line(file_content[j]))
		j--;
	map = ft_strstrdup(&file_content[i], j - i + 1);
	return (map);
}

void	reverse_str(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 2];
		str[len - i - 2] = tmp;
		i++;
	}
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**read_map(t_win *win, char *map)
{
	char	**res;
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_print_error_and_exit(win, "Map file not found\n ");
	res = ft_calloc(count_lines(fd) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	close(fd);
	fd = open(map, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		res[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	res[i] = NULL;
	close(fd);
	return (res);
}
