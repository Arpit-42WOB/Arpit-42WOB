/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:24:23 by amehrotr          #+#    #+#             */
/*   Updated: 2023/11/20 23:32:24 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_if_nums(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strstr_len(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_strstrdup(char **str, size_t len)
{
	char	**ret;
	size_t	i;

	ret = malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	ft_strstr_free(char **str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strstr_len(str);
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
