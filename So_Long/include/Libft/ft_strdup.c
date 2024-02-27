/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:00:13 by amehrotr          #+#    #+#             */
/*   Updated: 2023/05/22 20:00:16 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	size_t	l;
	char	*s2;

	l = ft_strlen(s1) + 1;
	s2 = malloc(l * sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, l);
	return (s2);
}
