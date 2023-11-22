/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalam <ahsalam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:00:13 by amehrotr          #+#    #+#             */
/*   Updated: 2023/10/25 20:38:17 by ahsalam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	size_t	l;
	size_t	i;
	char	*s2;

	i = 0;
	l = ft_strlen(s1) + 1;
	s2 = malloc(l * sizeof(char));
	if (!s2)
		return (NULL);
	s2[l - 1] = '\0';
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
