/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:59:43 by ahsalam           #+#    #+#             */
/*   Updated: 2023/11/20 23:32:03 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_space(int n)
{
	if ((n < 9 || n > 13) && n != 32)
		return (0);
	return (1);
}

int	ft_count_word(char const *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (!is_space(*str) && j == 0)
		{
			j = 1;
			i++;
		}
		else if (is_space(*str))
			j = 0;
		str++;
	}
	return (i);
}

char	*ft_fill_word(char const *str, int start, int finish)
{
	char	*words;
	int		i;

	i = 0;
	words = (char *)malloc(sizeof(char) * ((finish - start) + 1));
	while (start < finish)
	{
		words[i] = str[start];
		i++;
		start++;
	}
	words[i] = '\0';
	return (words);
}

char	**ft_spliting(char const *str)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**new;

	new = malloc(sizeof(char *) * (3));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(str))
	{
		if (!is_space(str[i]) && k < 0)
			k = i;
		else if ((is_space(str[i]) || i == ft_strlen(str)) && k >= 0)
		{
			new[j++] = ft_fill_word(str, k, i);
			k = -1;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}
