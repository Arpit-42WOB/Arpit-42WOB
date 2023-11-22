/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:18:38 by amehrotr          #+#    #+#             */
/*   Updated: 2023/06/01 20:19:50 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
