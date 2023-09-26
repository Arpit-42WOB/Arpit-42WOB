/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:10:22 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/07 12:06:07 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		len = 0;
	else if ((len + start) > l)
		len = l - start;
	sub = (char *) malloc((len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && j < l)
	{
		sub[i] = s[j];
		i++;
		j++;
	}
	sub[i] = '\0';
	return (sub);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

void	*ft_free_strmem(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_get_str(char **split, int index, char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0 && i != ft_strlen(s))
			index = i;
		else if ((s[i] == c || i == (ft_strlen(s))) && index >= 0)
		{
			split[j++] = ft_substr(s, index, (i - index));
			if (!split[j - 1])
			{
				ft_free_strmem(split);
				return (NULL);
			}
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	int		index;
	char	**split;

	i = count_words(s, c);
	split = (char **) malloc((i + 1) * sizeof(char *));
	if (!s || !(split))
		return (NULL);
	index = -1;
	split = ft_get_str(split, index, s, c);
	if (!split)
		return (NULL);
	return (split);
}
