/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:58:20 by arpit             #+#    #+#             */
/*   Updated: 2023/10/25 11:21:12 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			num++;
		}
		s++;
	}
	return (num);
}

static void	spliting(int words, char const *s, char c, char **tab)
{
	int	j;
	int	i;
	int	start;

	j = -1;
	i = 0;
	while (++j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strsub(s, start, i - start);
		i++;
	}
	tab[j] = NULL;
}

char	**ft_strsplit(const char *s, char c)
{
	int		words;
	char	**tab;

	if (!s || !c)
		return (NULL);
	words = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	spliting(words, s, c, tab);
	return (tab);
}
