/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:05:43 by amehrotr          #+#    #+#             */
/*   Updated: 2023/08/01 12:07:23 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fstr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	fstr = malloc (i + j + 1);
	if (!fstr)
		return (NULL);
	k = 0;
	while (k < i)
	{
		fstr[k] = s1[k];
		k++;
	}
	while (k < (i + j))
	{
		fstr[k] = s2[k - i];
		k++;
	}
	fstr[k] = '\0';
	if (s1)
		free((void *)s1);
	return (fstr);
}
