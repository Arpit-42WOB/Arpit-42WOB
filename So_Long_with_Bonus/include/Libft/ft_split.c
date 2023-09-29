/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:21 by amehrotr          #+#    #+#             */
/*   Updated: 2023/07/31 19:14:56 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
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

static void	*ft_free_strmem(char **split)
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

static char	**ft_get_str(char **split, int index, const char *s, char c)
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

char	**ft_split(char const *s, char c)
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
