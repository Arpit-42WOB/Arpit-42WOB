/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:08:49 by amehrotr          #+#    #+#             */
/*   Updated: 2023/06/02 10:11:54 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_clear_line(char *str)
{
	size_t	i;
	size_t	j;
	int		f;

	i = 0;
	j = 0;
	f = 0;
	while (str[i])
	{
		if (f)
			str[j++] = str[i];
		if (str[i] == '\n')
			f = 1;
		str[i++] = '\0';
	}
	return (f);
}

char	*get_next_line(int fd)
{
	static char	str_read[BUFFER_SIZE + 1];
	static char	*line;
	int			f;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_strjoin(0, str_read);
	if (ft_clear_line(str_read) != 0)
		return (line);
	f = read(fd, str_read, BUFFER_SIZE);
	if (f < 0)
	{
		free(line);
		return (NULL);
	}
	while (f > 0)
	{
		line = ft_strjoin(line, str_read);
		if (ft_clear_line(str_read) != 0)
			break ;
		f = read(fd, str_read, BUFFER_SIZE);
	}
	return (line);
}
