/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:24:50 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/21 18:15:43 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	find_max_len(t_win *win)
{
	int	max_len;
	int	i;

	max_len = 0;
	i = 0;
	while (win->map[i])
	{
		if (!is_empty_line(win->map[i]) && \
		(int)ft_strlen(win->map[i]) < max_len)
		{
			max_len = (int)ft_strlen(win->map[i]);
			if (win->map[i][(int)ft_strlen(win->map[i]) - 1] != '\n')
				max_len++;
		}
		i++;
	}
	return (max_len);
}

void	make_map_rectangular(t_win *win)
{
	int		max_len;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	max_len = find_max_len(win);
	while (win->map[i])
	{
		if ((int)ft_strlen(win->map[i]) < max_len)
		{
			tmp = malloc(max_len + 1);
			ft_strlcpy(tmp, win->map[i], max_len);
			j = (int)ft_strlen(tmp) - 2;
			while (++j < max_len - 1)
				tmp[j] = '1';
			tmp[j] = '\n';
			tmp[j + 1] = '\0';
			free(win->map[i]);
			win->map[i] = tmp;
		}
		i++;
	}
}

void	fill_with_ones(t_win *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == ' ')
				win->map[i][j] = '1';
			j++;
		}
		i++;
	}
}
