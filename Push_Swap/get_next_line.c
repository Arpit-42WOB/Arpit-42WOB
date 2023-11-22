/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:08:49 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 12:06:10 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fstr;
	size_t	k;
	size_t	j;

	if (!s2 || s2[0] == '\0')
		return (NULL);
	fstr = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fstr)
		return (NULL);
	k = 0;
	while (s1 && s1[k])
	{
		fstr[k] = s1[k];
		k++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		fstr[k++] = s2[j++];
	if (s2[j] == '\n')
		fstr[k++] = '\n';
	fstr[k] = '\0';
	if (s1)
		free(s1);
	return (fstr);
}

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
